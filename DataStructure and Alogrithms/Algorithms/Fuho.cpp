#include<bits/stdc++.h>
using namespace std;

void quickSort(int a[], int l, int r){
    int p = a[(l+r)/2];
    int i=l, j=r;
    while(i<j){
        while(a[i] < p){
            i++;
        }
        while(a[j]>p){
            j--;
        }
        if(i<=j){
            int temp = a[i];
            a[i]= a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(i<r){
        quickSort(a, i, r);
    }
    if(l<j){
        quickSort(a, l, j);
    }
}

int solve(int a[], int n){
	int k = 1;
	quickSort(a, 0, n-1);
	int stiffness = a[n-1];
	for (int i = n-2; i >=0; i--){
		k = k + 1;
		stiffness = stiffness - 1;
		if (stiffness > a[i]){
			stiffness = a[i];
		}
		if (stiffness == 0) return k;
	}
	return n;
}

int a[100001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << solve(a, n);
    return 0;
}