#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxValues(double w,double weight[],double value[],double ratio[],int nitem){
double cw=0;
double cv=0;
printf("Item Considered are:\n");
while(cw<w){
int item=getNextItem(weight,value,ratio,nitem);
if(item==-1){
break;
}
printf("Item %d\n",item+1);
if(cw+weight[item]<=w){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int getNextItem(double weight[],double value[],double ratio[],int nitem){
double highest=0;
int index=-1,i;
for(i=0;i<nitem;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
int main(){
int nitem,i;
double w;
double weight[MAX_ITEMS];
double value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("Enter the no' of items:");
scanf("%d",&nitem);
printf("Enter the weight of the items:\n");
for(i=0;i<nitem;i++){
scanf("%lf",&weight[i]);
}
printf("Enter the values/profit of the items:\n");
for(i=0;i<nitem;i++){
scanf("%lf",&value[i]);
}
for(i=0;i<nitem;i++){
ratio[i]=value[i]/weight[i];
}
printf("Enter the capacity of the knapsack:");
scanf("%lf",&w);
printf("The maximum value in a knapsack of capacity %2f is : %2f\n",w,computeMaxValues(w,weight,value,ratio,nitem));
return 0;
}
