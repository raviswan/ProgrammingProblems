#include <iostream>
#include <set>

/*More like TCP window implementation

The goal is to take an input seq number, and update the number of lost packets and out of order packets.

The rules are:
SeqNum < (MaxSeqNum-5): discard
else: keep track of 
lp - loss of packets
op: out of order packets
Duplicates are discarded
E.g.

Sqe No			3, 5, 4, 7, 7,  11, 8, 9, 17, 12, 12, 15
Lost Pkts:		0, 1, 0, 1, 1,  4,  3, 3,  7,  7, 7,  6
OutOfOrderPkts: 0, 0, 1, 1, 1,  1,  2, 3,  3,  3, 3,  4

*/


using namespace std;

int op = 0;
int lp = 0;
int maxSeqNum = -1;
set<int> window;
bool flag = false;

void checkPackets(int seqNo){
	if(!flag){
		maxSeqNum = seqNo;
		window.insert(seqNo);
		flag = true;
	}
	if(seqNo  <= maxSeqNum - 5){
		return;
	}
	else if(seqNo > maxSeqNum){
		if(seqNo - maxSeqNum >= 5){
			window.clear();
		}
		window.insert(seqNo);
		lp += seqNo - maxSeqNum - 1;
		maxSeqNum =  seqNo;
	}
	else if ( (seqNo > (maxSeqNum - 5)) && (seqNo < maxSeqNum) ){
		if(window.find(seqNo) == window.end()){
			window.insert(seqNo);
			op += 1;
			lp = (lp == 0 ? 1: lp - 1);
		}
	}
	cout<<"seq no. ="<<seqNo<<"; maxSeqNo = "<<maxSeqNum<<"; lostpackets = "<<lp<<"; out_of_order packets = "<<op<<endl;
	return;
}

int main(){
	int a[] = { 3,5,4,7, 7,11,8,9, 17, 12,12, 15, 18, 16};
	for (int i=0; i< sizeof(a)/sizeof(*a); ++i){
		checkPackets(a[i]);
	}
	return 1;
}