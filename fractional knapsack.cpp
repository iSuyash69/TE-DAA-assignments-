#include <iostream>
using namespace std;

void takeInput(int n,int weights[],int profits[],int& capacity){
    for(int i=0;i<n;i++){
        cout<<"Enter weight of "<<i+1<<" item: ";
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        cout<<"Enter profit of "<<i+1<<" item: ";
        cin>>profits[i];
    }
    cout<<"Enter capacity of knapsack: ";
    cin>>capacity;    
}

void pwRatio(int n,int weights[],int profits[],double pwRatios[]){
    for(int i=0;i<n;i++){
        pwRatios[i]=static_cast<double>(profits[i])/weights[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pwRatios[i]<pwRatios[j]){
                std::swap(weights[i],weights[j]);
                std::swap(profits[i],profits[j]);
                std::swap(pwRatios[i],pwRatios[j]);
            }
        }
    }
}

void giveOutput(int n,int weights[],int profits[],int capacity){
    double solution=0;
    for(int i=0;i<n;i++){
        if(weights[i]<=capacity){
            solution+=profits[i];
            capacity-=weights[i];
        }
        else{
            double remainingValueProfit=capacity*(static_cast<double>(profits[i])/(weights[i]));
            solution+=remainingValueProfit;
            capacity-=weights[i];
            break;
        }
    }
    cout<<"Maximum profit will be: "<<solution;
}

int main(){
    int n;
    
    cout<<"Enter total no. of items: ";
    cin>>n;
    
    int capacity;
    int profits[n];
    int weights[n];
    double pwRatios[n];
    
    takeInput(n,weights,profits,capacity);
    pwRatio(n,weights,profits,pwRatios);
    giveOutput(n,weights,profits,capacity);
}

