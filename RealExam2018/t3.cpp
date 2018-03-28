#include<iostream>

using namespace std;

#define M 13

//��ó�ջ���и���
//����������ʽ 
int getCount(int n){
	int sum1=1,sum2=1;
	for(int i=0;i<n;i++){
		sum1*=(2*n-i);
		sum2*=(n-i);
	}
	return sum1/(sum2*(n+1));
}

//�ж�����sou�Ƿ���ϳ�ջ���� 
bool isOk(char sou[M],int n){
	for(int i=0;i<n;i++){
		char buf[M];
		int top=-1;
		for(int j=i+1;j<n;j++){
			if(sou[j]<sou[i]) buf[++top]=sou[j];
		}
		for(int j=0;j<top;j++){
			if(buf[j]<buf[j+1]) return false;
		}
	}
	return true;
}

//�ж�c�Ƿ�������sou�� 
bool isSame(char sou[M],int n,char c){
	for(int i=0;i<n;i++){
		if(sou[i]==c) return false;
	}
	return true;
}

//�ݹ飬�������ظ���Nλ���У����ж��Ƿ���ϳ�ջ���򣬷��Ͼ���� 
void func(char sou[M],int n,int N){
	if(n==N){
		if(isOk(sou,n)){
			for(int i=0;i<n;i++){
				cout<<sou[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i=0;i<N;i++){
		char temp='a'+i;
		if(isSame(sou,n,temp)){
			sou[n]=temp;
			func(sou,n+1,N);
		}
	}
}

int main(){
	int n;
	cin>>n;
	char sou[M];
	
	//�����ջ���еĸ��� 
	int count=getCount(n);
	cout<<count<<endl;
	
	//�ݹ������ջ���� 
	func(sou,0,n);
	
	return 0;
}
