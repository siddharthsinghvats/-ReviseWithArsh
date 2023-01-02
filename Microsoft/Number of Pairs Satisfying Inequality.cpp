
#define ll long long
class Solution {
public:
    ll merge(int a[], int s, int mid, int e ,int &d){
        int left[mid-s+1];
        int right[e-mid];
        int j=0;
        for(int i =s;i<=mid;i++) left[j++]= a[i];
        j=0;
        for(int i =mid+1;i<=e;i++)right[j++] = a[i];
        int full[e-s+1];
        j=0;
        int n = mid-s+1;
        int m = e-mid;
        int k=0,i=0;
        ll cnt =0;
        while(i<n&&j<m){
            if(left[i]<=right[j]+d){
                cnt+=m-j;
            i++;
            }else{
               j++;
            }
        }
       i=0,j=0;

        while(i<n&&j<m){
            if(left[i]<=right[j]){
                full[k++] = left[i++];
            }else{
                full[k++] = right[j++];
            }
        }
        while(i<n) full[k++] = left[i++];
        while(j<m) full[k++] = right[j++];
        k=0;
        for(int i =s;i<=e;i++) a[i] = full[k++];
        return cnt;
    }
    ll merge_sort(int a[], int s, int e,int &d){
       
        int mid  =(s+e)/2;
        ll cnt =0;
        if(s<e){
            cnt+=merge_sort(a,s,mid,d);
            cnt+=merge_sort(a,mid+1,e,d);
            cnt+=merge(a,s,mid,e,d);
        }
        return cnt;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums1.size();
        int a[n];
        for(int i = 0;i<n;i++){
            a[i] = nums1[i]-nums2[i];
        }
        return merge_sort(a,0,n-1,diff);
    }
};
