/*
                IftekharMd.Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll  long long
#define ull  unsigned long long
#define ld  long double
#define printArray(i,a,n)  f(i,n)cout<<a[i]<<" "; cout<<endl;
#define printSet(a)  for(auto setData:a) cout<<setData<<" ";cout<<endl;
#define printMap(a)  for(auto mapData:a) cout<<mapData.first<<" "<<mapData.second<<endl;
#define printVector(a)  for(auto vectorData:a)cout<<vectorData<<" ";cout<<endl;
#define printLinkedList()  temp=head;while(temp){cout<<temp->data<<" ";temp=temp->post;} cout<<endl;

#define pb(x)  push_back(x)
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(str,x)   stringstream demo(str); demo >> x;
#define intToSting(x,get)   stringstream demu; demu << x; get = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define TxtTest   freopen("C:/Users/Iftekhar/Documents/what/input.txt", "r", stdin);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x) cerr << #x << " = " << x << endl;

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

ll cnt =1;

struct node 
{
        ll data;
        node *left;
        node *right;
} *newnode, *head= NULL, *temp;

ll searchBST(node * root, ll k)
{
        if(root>=k) return -1;
}
node * createNode(ll x)
{
        newnode  = new node();
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        return newnode;
}
void insertBST(node * root, ll x)
{
        cnt++;
        if(!root->left && x<=root->data){
                root->left = createNode(x);
                return;
        }
        else if(!root->right && x>root->data){
                root->right = createNode(x);
                return;
        }
        else if(root->left && x<=root->data) insertBST(root->left, x);
        else if(root->right && x>root->data) insertBST(root->right, x);
}
int main()
{
        //FastIO;
        ll n;
        cin>>n;
        vector<ll> a(n);
        set<ll> st;
        for(auto &x:a){
                cin>>x;
                st.insert(x);
        }
        vector<ll>b(all(st));
        for(auto x:b){
                if(!head) {
                        node * newbie = createNode(x);
                        head = newbie;
                        continue;
                }
                insertBST(head, x);
        }
        return 0;
}