/*Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.*/

#include <bits/stdc++.h>
using namespace std;
class PriorityQueue {
    vector<int> pq;
    public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int ci=pq.size()-1;
        while(ci>0){
            int pi=(ci-1)/2;
            if(pq[ci]>pq[pi]){
                int temp=pq[ci];
                pq[ci]=pq[pi];
                pq[pi]=temp;
            }else{
                break;
            }
            ci=pi;
        }
    }    
    int removeMax(){
        if(this->isEmpty()){
            return INT_MIN;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int pi=0;
        int left=2*pi+1;
        int right=2*pi+2;
        int maxindex;
        while(left<pq.size()){
            maxindex=pi;
           // int maxi=max(pq[pi],max(pq[left],pq[right]));
           /* if(maxi==pq[pi]){
                break;
            }*/
            int maxchild=max(pq[left],pq[right]);
            if(maxchild==pq[left] /* && left<pq.size()*/&& pq[left]>pq[pi]){
                maxindex=left;
            }
            if(maxchild==pq[right] && right<pq.size() && pq[right]>pq[pi]){
                maxindex=right;
            }
            if(maxindex==pi){
                break;
            }else{
                int temp=pq[pi];
                pq[pi]=pq[maxindex];
                pq[maxindex]=temp;
                pi=maxindex;
                left=2*pi+1;
                right=2*pi+2;
            }
            
        }
        return ans;
    }
    
    
};
