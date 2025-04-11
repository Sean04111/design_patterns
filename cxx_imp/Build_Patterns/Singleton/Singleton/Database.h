#pragma once
#include <atomic>
#include <mutex>

struct Database_v1 {
	/**
	* \brief please do not create more than one instance.
	*/
	/*
	* 在构造函数中添加计数器
	*/
	Database_v1() {
		static int counter = 0;
		if (++counter > 1) {
			throw("cannot make >1 database");
		}
	};

};

static Database_v1 database{};

/* 这段代码只有在cxx11 过后才是安全的
 * 因为cxx11 过后要求一个static变量只能由一个线程来进行初始化
 * 所以在cxx11之前，这样写会出现data race问题；
 * 这样写的还有一个潜在问题是这种全局静态的变量的问题：
 * 如果Database的析构函数里面使用了另一个单例对象，那么就会可能出现崩溃
 */

Database_v1& get_database() {
	static Database_v1 database;
	return database;
}


struct Database_v2 {
protected:
	Database_v2() {};
public:
	static Database_v2& get_instace() {
		static Database_v2 instance{};
		return instance;
	}

	Database_v2(const Database_v2& other) = delete;
	Database_v2& operator=(const Database_v2& other) = delete;
	Database_v2(Database_v2&&) = delete;
	Database_v2& operator=(Database_v2&&) = delete;
};

/*在cxx11 之前的单例模式，使用double-check 来保证全局变量只被一个线程初始化*/
struct Database_v3 {
public: 
	static Database_v3& get_instance();
private:
	static std::atomic<Database_v3*> instance;
	static std::mutex mu;
};

Database_v3& Database_v3::get_instance() {
	Database_v3* db = instance.load(std::memory_order_acquire);
	if (!db) {
		std::lock_guard<std::mutex> lock(mu);
		db = instance.load(std::memory_order_acquire);
		/* 防止第二个线程在加锁之前已经初始化成功了这个全局对象*/
		if (!db) {
			db = new Database_v3();
			instance.store(db, std::memory_order_release);
		}
	}
}

/*使用thread_local来实现线程级单例*/
struct Database_v4 {
protected:
	Database_v4() {};
public:
	static Database_v4& get_instance() { 
		/*thread_local 可以理解为线程级别的static*/
		thread_local Database_v4 instance{};
		return instance;
	};
};

/*单态模式*/
class Printer {
private:
	static int a;
public:
	void set_a(int new_a) {a = new_a;}
	int get_a() { return a; }
};




void use() {
	/*
	 * 注意这里要用auto& 因为，auto在编译器中默认是值类型，所以就会使用database的复制构造函数
	 */
	auto& db = Database_v2::get_instace();
}