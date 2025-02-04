/*Rahul Counting Trees
Send Feedback
You are given a Binary tree T and an integer K. Input binary Trees T is consisting of N (numbered from 1 to N) nodes rooted at node 1 and each node has a number written on it, where the number written on the ith node is A[i].
Now, Rahul needs to find the number of unordered triplets (i,j,k), such that node i is an ancestor of node j as well as node k, and A[i]+A[j]+A[k]>=K
A node x is considered an ancestor of another node y, if x is parent of y or x is an ancestor of parent of y.
Help Rahul for the same.
Input Format :
Line 1 : 2 space separated integers N and K. 
Line 2 : N space separated integers, where the ith integer denotes A[i].
Line 3 : N-1 space separated integers, where the ith integer represents the parent of node i+1.
Output Format :
Print the required answer on a single line.
Contraints :
1<= N <= 500
0<= A[i] <=10^9
Sample Input 1 :
5 6
1 2 3 4 5
1 2 2 1
Sample Output 1 :
7
Sample Input 2 :
20 63
66 1 20 77 66 71 5 17 12 49 51 14 8 41 54 45 54 77 26 17
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
Sample Output 2 :
252*/

ll anc[510][510]={0};
int main(){
	ll n, K;cin>>n>>K;
	//assert(0 <= K and K <= 1e9);
	//assert(1 <= n and n <= 500);
	ll a[1000];
	ll par[1000];
	for(ll i=1; i<=n; i++){
		cin>>a[i];
		//assert(0 <= a[i] and a[i] <= 1e9);
	}
	for(ll i=2; i<=n; i++){
		ll temp; cin>>temp;
		//assert(1 <= temp and temp <= i);
		par[i] = temp;
	}
	for(ll i=2; i<=n; i++){
		ll x = i;
		while(x != 1){
			x = par[x];
			anc[x][i] = 1;
		}
	}
	ll ans = 0;
	for(ll i=1; i<=n; i++)
	for(ll j=1; j<=n; j++)
	for(ll k=1; k<=n; k++){
		if(i == j or j == k or i == k)continue;
		if(anc[i][j] and anc[i][k] and a[i]+a[j]+a[k] >= K){
			ans++;
		}	
	}	
	cout<<ans/2<<endl;	
	return 0;
}


