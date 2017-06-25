#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>


using namespace std;
const int PRODUCER_COUNT  = 2;
const int CONSUMER_COUNT = 4;


class WorkerQueue{
	public:
		void add(int elem){
				unique_lock<mutex> locker(mu);
				q.push(elem);
				cout<<"Produced elem "<<q.back()<<endl;
				locker.unlock();
				cond.notify_one();
		}

		int remove(int threadID){
			unique_lock<mutex> locker(mu);
			cond.wait(locker, [&]() { return !q.empty(); });	
			a = q.front();
			q.pop();
			cout<<"Thread: "<<threadID<<" consumed "<<a<<endl;
			locker.unlock();
			return a;
		}
		void operator()(){
			return;
		}

	private:
		int a;
		queue<int> q;
		mutex mu;
		condition_variable cond;
};

class Consumer{
	public:
		Consumer(WorkerQueue& wq):wq(wq){

		}
		int removeElem(int threadID){
			return wq.remove(threadID);
		}
		int operator()(int i){
			int a;
			while(1){
				{	
					removeElem(i);
				}
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
	private:
		WorkerQueue& wq;
};

class Producer{
	public:
		Producer(WorkerQueue& wq):wq(wq){
		}
		void operator()(){
			while(1){
				{
					++elem;
					wq.add(elem);
				}
				this_thread::sleep_for(chrono::milliseconds(100));
			}
		}
	private: 
		WorkerQueue& wq;
		int elem = 1000;
};



int main(){
	WorkerQueue wq;
	Consumer a(ref(wq));
	Consumer b(ref(wq));
	Producer p(ref(wq));
	thread producerThread(ref(p));
	thread c1Thread(ref(a), 1);
	thread c2Thread(ref(b), 2);

	//vector<thread> consumerThreads;
	//vector<Consumer*> consumerVector;
	//vector<Producer*> producerVector;
	// //vector<thread> producerThreads;
	// for (int i = 0 ; i < PRODUCER_COUNT; ++i){
	// 	producerVector.push_back(new Producer(&wq));
	// 	thread t(new Producer(&wq));
	// 	producerThreads.push_back(t);

	// }
	// for (int i = 0 ; i < CONSUMER_COUNT; ++i){
	// 	consumerVector.push_back(new Consumer(&wq));
	// 	thread t(consumerVector[i]);
	// 	consumerThreads.push_back(t);

	// }
	//cout<<"Number of consumer threads = "<<consumerVector.size()<<endl;
	//cout<<"number of producers threads  = "<<producerVector.size()<<endl;
	producerThread.join();
	c1Thread.join();
	c2Thread.join();
	return 1;
}