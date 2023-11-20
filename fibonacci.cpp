#include <iostream>
using namespace std;

int recursive(int i){
    if(i<2){
        return i;
        
    }
    else{
        return recursive(i-1)+recursive(i-2);
    }
}

void nonRecursive(int n){
    
    if(n==0){
        cout<<n<<" ";
    }
    else{
        int a=0;
        int b=1;
        cout<<a<<" "<<b<<" ";
        for(int i=2;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
            cout<<c<<" ";
        }
    }
}

int recursiveDP(int i,int memo[]){
    if(i<2){
        return i;
    }
    if(memo[i]!=-1){
        return memo[i];
    }
    else{
        memo[i]=recursiveDP(i-1,memo)+recursiveDP(i-2,memo);
        return memo[i];
    }
}

int main(){
    int n;
    int choice;
    char ch;
    
    do{

        cout<<"\n1.Recursive \n2.Non-Recursive\n3.Recursive (using DP)\n4.Exit\nYour choice:\t";
        cin>>choice;
        
        switch(choice){
            case 1:{
                cout<<"Enter the number to get its fibonacci series: ";
                cin>>n;
                cout<<"Fibonacci series: ";
                for(int i=0;i<n;i++){
                    cout<<recursive(i)<<" ";
                }
                break;
            }
            case 2:{
                cout<<"Enter the number to get its fibonacci series: ";
                cin>>n;
                cout<<"Fibonacci series: ";
                nonRecursive(n);
                break;
            }
            case 3:{
                cout<<"Enter the number to get its fibonacci series: ";
                cin>>n;
                int memo[n+1];
                
                for(int i=0;i<=n;i++){
                    memo[i]=-1;
                }

                for(int i=0;i<=n;i++){
                    cout<<recursiveDP(i,memo)<<" ";
                }
                break;
            }
            case 4:{
                cout<<"\n\nProgram Ended";
                return 0;
                break;
            }
            default:
                cout<<"\nWrong choice\n";
        }
        
        cout<<"\n\nDo you want to continue(Y/N): ";
        cin>>ch;
    }while(ch=='Y' || ch=='y');
    
    cout<<"\nProgram Ended";
    return 0;
    
}
