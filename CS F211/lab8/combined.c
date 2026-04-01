//q1

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX]; int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[l]>heap[r]){
            smallest=r;
        }
        if(heap[i]>heap[smallest]){
            swap(&heap[i], &heap[smallest]);
            heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

void remove_top(){
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
}

int main(){
    int k, n, x;
    scanf("%d %d", &k, &n);

    int *arr=malloc(n*sizeof(*arr));
    int *ans=malloc(n*sizeof(*ans));

    for(int i=0; i<n; i++){
        scanf("%d", &x);

        if(size<k){
            insert(x);
        }
        else if(x>heap[0]){
            remove_top();
            insert(x);
        }

        if(size<k){
            ans[i]=-1;
        }
        else{
            ans[i]=heap[0];
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    free(arr); free(ans);
    return 0;
}



//q2

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX]; int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[l]>heap[r]){
            smallest=r;
        }
        if(heap[i]>heap[smallest]){
            swap(&heap[i], &heap[smallest]);
            heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

int remove_top(){
    int t=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
    return t;
}

int main(){
    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }

    int cost=0;

    while(size>1){
        int a=remove_top();
        int b=remove_top();
        int s=a+b;
        cost+=s;
        insert(s);
    }
    printf("%d", cost);
    return 0;
}



//q3

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int minH[MAX]; int minS=0;
int maxH[MAX]; int maxS=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void min_heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(minH[i]<minH[p]){
            swap(&minH[i], &minH[p]);
            min_heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void min_heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<minS){
        int smallest=l;
        if(r<minS && minH[l]>minH[r]){
            smallest=r;
        }
        if(minH[i]>minH[smallest]){
            swap(&minH[i], &minH[smallest]);
            min_heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void min_insert(int x){
    minH[minS++]=x;
    min_heapify_up(minS-1);
}

int min_remove_top(){
    int t=minH[0];
    minH[0]=minH[minS-1];
    minS--;
    min_heapify_down(0);
    return t;
}

void max_heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(maxH[i]>maxH[p]){
            swap(&maxH[i], &maxH[p]);
            max_heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void max_heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<maxS){
        int largest=l;
        if(r<maxS && maxH[l]<maxH[r]){
            largest=r;
        }
        if(maxH[i]<maxH[largest]){
            swap(&maxH[i], &maxH[largest]);
            max_heapify_down(largest);
        }
        else{
            return;
        }
    }
}


void max_insert(int x){
    maxH[maxS++]=x;
    max_heapify_up(maxS-1);
}

int max_remove_top(){
    int t=maxH[0];
    maxH[0]=maxH[maxS-1];
    maxS--;
    max_heapify_down(0);
    return t;
}

int main(){
    int n, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);

        if(maxS==0 || x<=maxH[0]){
            max_insert(x);
        }
        else{
            min_insert(x);
        }

        if(minS+1<maxS){
            min_insert(max_remove_top());
        }
        else if(minS>maxS){
            max_insert(min_remove_top());
        }

        if(minS==maxS){ 
            printf("%.1f ", (minH[0]+maxH[0])/2.0);
        }
        else{
            printf("%.1f ", (float)(maxH[0]));
        }
    }

    return 0;
}



//q4

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;

struct Node{
    int sum;
    int i;
    int j;
};

struct Node heap[MAX];

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[p].sum>heap[i].sum){
            swap(&heap[p], &heap[i]);
            up(p);
        }   
        else{
            return;
        }
    }
    else{
        return;
    }
}

void down(int i){
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        int smallest=l;
        if(r<size){
            if(heap[l].sum>heap[r].sum){
                smallest=r;
            }
        }
        if(heap[i].sum>heap[smallest].sum){
            swap(&heap[i], &heap[smallest]);
            down(smallest);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void insert(struct Node x){
    heap[size++]=x;
    up(size-1);
}

struct Node remove_top(){
    struct Node t=heap[0];
    heap[0]=heap[size-1];
    size--;
    down(0);
    return t;
}

int main(){
    int n1, n2, k;

    scanf("%d %d", &n1, &n2);
    int *arr1=malloc(n1*sizeof(*arr1));
    int *arr2=malloc(n2*sizeof(*arr2));

    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    scanf("%d", &k);

    for(int i=0; i<n1; i++){
        insert((struct Node){arr1[i]+arr2[0], i, 0});
    }

    while(k--){
        struct Node t=remove_top();
        printf("%d %d\n", arr1[t.i], arr2[t.j]);

        if(t.j+1<n2){
            insert((struct Node){arr1[t.i]+arr2[t.j+1], t.i, t.j+1});
        }
    }

    free(arr1); free(arr2);
    return 0;
}



//q5

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct Node{
    int val, r, c;
};

struct Node heap[MAX]; int size=0;

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;

        if(heap[p].val>heap[i].val){
            swap(&heap[p], &heap[i]);
            up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}


void down(int i){
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[r].val<heap[l].val){
            smallest=r;
        }

        if(heap[i].val>heap[smallest].val){
            swap(&heap[i], &heap[smallest]);
            up(smallest);
        }
        return;
    }
    else{
        return;
    }
}

void insert(struct Node x){
    heap[size++]=x;
    up(size-1);
}

struct Node remove_top(){
    struct Node t=heap[0];
    heap[0]=heap[size-1];
    size--;
    down(0);
    return t;
}

int main(){
    int n, k;
    scanf("%d", &n);

    int arr[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        insert((struct Node){arr[i][0], i, 0});
    }

    struct Node t;

    for(int i=0; i<k; i++){
        t=remove_top();
        if(t.c+1<n){
            insert((struct Node){arr[t.r][t.c+1], t.r, t.c+1});
        }
    }

    printf("%d", t.val);
    return 0;
}




//q6

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX]; int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[l]>heap[r]){
            smallest=r;
        }
        if(heap[i]>heap[smallest]){
            swap(&heap[i], &heap[smallest]);
            heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

int remove_top(){
    int t=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
    return t;
}

int main(){
    int n;
    int visited[10000];
    scanf("%d", &n);

    insert(2); visited[2]=1;
    insert(5); visited[5]=1;
    insert(7); visited[7]=1;

    int count=0; int ans;
    while(count<n){
        ans=remove_top();
        count++;

        if(!visited[ans*2]){
            insert(ans*2); visited[ans*2]=1;
        }
        if(!visited[ans*5]){
            insert(ans*5); visited[ans*5]=1;
        }
        if(!visited[ans*7]){
            insert(ans*7); visited[ans*7]=1;
        }
    }

    printf("%d", ans);
    return 0;
}



//q7

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;
int heap[MAX];

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]>heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int largest=l;
        if(r<size && heap[l]<heap[r]){
            largest=r;
        }
        if(heap[i]<heap[largest]){
            swap(&heap[i], &heap[largest]);
            heapify_down(largest);
        }
        else{
            return;
        }
    }
}

void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

int remove_top(){
    int t=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
    return t;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    char *arr=calloc(n, sizeof(*arr));
    int freq[26]={0};

    for(int i=0; i<n; i++){
        scanf(" %c", &arr[i]);
        freq[arr[i]-'A']++;
    }

    for(int i=0; i<26; i++){
        if(freq[i]>0){
            insert(freq[i]);
        }
    }
    
    int time=0;

    while(size>0){
        int temp[100]; int t=0;
        int cycle=k+1;

        for(int i=0; i<cycle; i++){
            if(size>0){
                int f=remove_top();
                if(f-1>0){
                temp[t++]=f-1;
                }
                time++;
            }
            else if(t>0){
                time++;
            }            
        }

        for(int i=0; i<t; i++){
            insert(temp[i]);
        }
    }

    printf("%d ", time);
    free(arr);
    return 0;

}



//q8

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;
int visited[MAX][MAX];

struct Node{
    int h;
    int x;
    int y;
};

struct Node heap[MAX];

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[p].h>heap[i].h){
            swap(&heap[p], &heap[i]);
            up(p);
        }   
        else{
            return;
        }
    }
    else{
        return;
    }
}

void down(int i){
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        int smallest=l;
        if(r<size){
            if(heap[l].h>heap[r].h){
                smallest=r;
            }
        }
        if(heap[i].h>heap[smallest].h){
            swap(&heap[i], &heap[smallest]);
            down(smallest);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void insert(struct Node x){
    heap[size++]=x;
    up(size-1);
}

struct Node remove_top(){
    struct Node t=heap[0];
    heap[0]=heap[size-1];
    size--;
    down(0);
    return t;
}


int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int a[MAX][MAX];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            visited[i][j]=0;
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0; i<r; i++){
        visited[i][0]=1; visited[i][c-1]=1;
        insert((struct Node){a[i][0], i, 0});
        insert((struct Node){a[i][c-1], i, c-1});
    }

    for(int j=1; j<c-1; j++){
        visited[0][j]=1; visited[r-1][j]=1;
        insert((struct Node){a[0][j], 0, j});
        insert((struct Node){a[r-1][j], r-1, j});
    }

    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    int water=0;

    while(size>0){
        struct Node curr=remove_top();

        for(int i=0; i<4; i++){
            int nx=curr.x+dx[i];
            int ny=curr.y+dy[i];

            if(nx>=0 && ny>=0 && nx<r && ny<c && visited[nx][ny]!=1){
                visited[nx][ny]=1;
                int newh=a[nx][ny];
                if(a[nx][ny]<curr.h){
                    water+=curr.h-a[nx][ny];
                    newh=curr.h;
                }

                insert((struct Node){newh, nx, ny});

            }
        }
    }
    printf("%d", water);
    return 0;
}



//q9

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX]; int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[l]>heap[r]){
            smallest=r;
        }
        if(heap[i]>heap[smallest]){
            swap(&heap[i], &heap[smallest]);
            heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

void remove_top(){
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
}

struct job{
    int d;
    int r;
};

int main(){
    int n;
    scanf("%d", &n);

    struct job jobs[100];

    for(int i=0; i<n; i++){
        scanf("%d %d", &jobs[i].d, &jobs[i].r);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(jobs[i].d>jobs[j].d){
                struct job t = jobs[i];
                jobs[i]=jobs[j];
                jobs[j]=t;
            }
        }
    }

    for(int i=0; i<n; i++){
        insert(jobs[i].r);

        if(size>jobs[i].d){
            remove_top();
        }
    }

    int sum=0;
    for(int i=0; i<size; i++){
        sum+=heap[i];
    }

    printf("%d", sum);
    return 0;
}




//q10

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;

struct Node{
    int val;
    int row;
    int col;
};

int maxVal=-10000;

struct Node heap[MAX];

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[p].val>heap[i].val){
            swap(&heap[p], &heap[i]);
            up(p);
        }   
        else{
            return;
        }
    }
    else{
        return;
    }
}

void down(int i){
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        int smallest=l;
        if(r<size){
            if(heap[l].val>heap[r].val){
                smallest=r;
            }
        }
        if(heap[i].val>heap[smallest].val){
            swap(&heap[i], &heap[smallest]);
            down(smallest);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void insert(struct Node x){
    heap[size++]=x;
    up(size-1);
}

struct Node remove_top(){
    struct Node t=heap[0];
    heap[0]=heap[size-1];
    size--;
    down(0);
    return t;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[100][100];
    int size[100];

    for(int i=0; i<n; i++){
        scanf("%d", &size[i]);

        for(int j=0; j<size[i]; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        insert((struct Node){arr[i][0], i, 0});
        if(maxVal<arr[i][0]){
            maxVal=arr[i][0];
        }
    }

    int start=0; int end=10000;
    while(1){
        struct Node t=remove_top();
        if ((maxVal - t.val < end - start) || ((maxVal - t.val == end - start) && (t.val < start))) {
            start = t.val;
        end = maxVal;
        }

        if(t.col+1<size[t.row]){
            insert((struct Node){arr[t.row][t.col+1], t.row, t.col+1});
            if(maxVal<arr[t.row][t.col+1]){
                maxVal=arr[t.row][t.col+1];
            }
        }
        else{
            break;
        }
    }
    printf("%d %d", start, end);
    return 0;
}