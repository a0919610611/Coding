#define maxn 10000000
int euler[maxn+5];
bool is_prime[maxn+5];
inline void init_euler(){
    is_prime[1]=1;//一不是質數
    for(int i=1;i<=maxn;i++)euler[i]=i;
    for(int i=2;i<=maxn;i++){
        if(!is_prime[i]){//是質數
            euler[i]--;
            for(int j=i<<1;j<=maxn;j+=i){
                is_prime[j]=1;
                euler[j]=euler[j]/i*(i-1);
            }
        }
    }
}
inline int Euler(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
