#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N=1e3;
char a[250][250];
bool vis[N][N];
int n,m;
ll sheep,wol,s1,v1;
int flag=0;

void dfs(int i,int j){
    if(i<0||j<0||i>=n||j>=m||a[i][j]=='$'||a[i][j]=='#') return;
    if(i==0||j==0||i==n-1||j==m-1){
            a[i][j]='$';a[i][j]='$';
        s1+=sheep;v1+=wol;
        flag=1;
        return;
        //flag=1;
    }

if(a[i][j]=='k') sheep++;
if(a[i][j]=='v') wol++;
a[i][j]='$';
int dr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
for(int k=0;k<4;k++){
    int cx=i+dr[k][0];
    int cy=j+dr[k][1];
    dfs(cx,cy);
}

}
int main(){

    //int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //ll s1=0,v1=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]!='#'||a[i][j]!='$'){
            dfs(i,j);
            if(flag==0){
            if(sheep>wol){
            s1+=sheep;}
            else{
                v1+=wol;
            }
           // sheep=0,wol=0;
        }
        flag=0;
        sheep=0,wol=0;
        }
    }
   }
   cout<<s1<<" "<<v1;




}
