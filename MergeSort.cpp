#include<bits/stdc++.h>
using namespace std;
void MergeSort(int a[],int low,int mid,int high);
void MergeFun(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
            MergeFun(a,low,mid);
            MergeFun(a,mid+1,high);
            MergeSort(a,low,mid,high);
    }

}
void MergeSort(int a[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];

    for(int i=0;i<n1;++i)
    left[i]=a[low+i];

    for(int j=0;j<n2;++j)
    right[j]=a[mid+j+1];

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;

    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }

}
int main()
{
    int n;
    cout<<"How many elements print are you in a array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;++i)
    cin>>arr[i];

    MergeFun(arr,0,n-1);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    return 0;
}


