#include <stdio.h>
#define maxn 100001
int n,i,a[maxn];
// duyet truoc
void preorder(int a[], int i, int n)
{
    printf("%d ", a[i]);
    if(2*i <= n) preorder(a, 2*i, n);
    if(2*i+1 <= n) preorder(a, 2*i+1, n);
}

// duyet giua
void inorder(int a[],int i,int n)
{
    if(2*i <= n) inorder(a, 2*i, n);
    printf("%d ", a[i]);
    if(2*i+1 <= n) inorder(a, 2*i+1, n);
}

// duyet sau
void postorder(int a[],int i,int n)
{
    if(2*i <= n) postorder(a, 2*i, n);
    if(2*i+1 <= n) postorder(a, 2*i+1, n);
    printf("%d ", a[i]);
}

// ham hoan doi gia tri
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// ham vun dong
void buildheap(int a[], int i, int n)
{
    int maxchild = i;// gia su nut con lon nhat dang chinh la nut cha
    int left = 2*i;
    int right = 2*i+1;
    if( left <= n && a[left] > a[maxchild] ) maxchild = left;// con lon nhat la con trai
    if( right <= n && a[right] > a[maxchild] ) maxchild = right;// con lon nhat la con phai
    if(maxchild != i){
        swap(&a[i], &a[maxchild]);// doi gia tri nut cha cho nut con lon nhat
        buildheap(a, maxchild, n);// vun dong tiep cho con lon nhat
    }
}

int main(){
    printf("Nhap n: ");
    scanf("%d",&n);
    printf("Cay nhin phan la:  ");
    for(i = 1; i <= n; i++) scanf("%d",&a[i]);

    printf("\nDuyet truoc: ");   
    preorder(a,1,n);
    printf("\nDuyet giua: ");
    inorder(a,1,n);
    printf("\nDuyet sau: ");
    postorder(a,1,n);

    for(i = n/2; i>= 1;i--) buildheap(a,i,n);
    printf("\nDuyet truoc sau khi da vun dong: ");   
    preorder(a,1,n);

    return 0;
}
