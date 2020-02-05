#include <iostream>

using namespace std;
void create(int**M, int m, int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            cout<<"Enter value for cell ["<<i<<"]["<<j<<"]: ";
            cin >> M[i][j];
        }
    for(int i=0; i<m; i++)
        {
        for(int j=0; j<n; j++) cout<<M[i][j]<< " ";
        cout<<endl;
        }
}
void TPN(int**M,int**p, int m, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            p[i][j]=M[j][i];

        }
}
void MLT(int**M, int m, int n, int k)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) M[i][j]*=k;
}
void SKL(int**M, int**N, int**p, int m, int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)p[i][j]=M[i][j]+N[i][j];
}
void PRD(int**M, int**N, int**p, int m, int n, int k)
{
    int sum = 0;
    for(int i=0; i<m; i++)
        for(int j=0; j<k; j++)
    {
        for(int x=0; x<n; x++)sum+=M[i][x]*N[x][j];
        p[i][j]=sum;
        sum = 0;
    }
}
int DET(int**M, int m)
{
    if(m==1)return M[0][0];
    if(m==2)return (M[0][0]*M[1][1])-(M[0][1]*M[1][0]);
    else
    {
        int**N=new int*[m-1];
        for(int i=0; i<m-1; i++)N[i] = new int[m-1];
        int S=0, i=0, z=1;
        for(i; i<m; i++)
        {
            for(int j=0; j<m-1; j++)
                for(int k=0; k<m; k++)
                N[j][k] = M[j+1][k];
            for(int j=0; j<m-1;j++)
                for(int k=i; k<m-1; k++)
                N[j][k] = N[j][k+1];
            int d = DET(N, m-1);
            S+=z*M[0][i]*d;
            d = -d;
        }
        delete N;
        return S;
    }
}
int main()
{
    cout<<" This is universal matrix operator"<<endl;
    int m, n;
    cout<<"Enter parameters of your matrix"<<endl;
    cin >> m >> n;
    int **M;
    M=new int*[m];
    for(int i=0; i<n; i++) M[i] = new int[n];

    create(M, m, n);
    int C = 1;
    while(C==1)
    {
        int sel;
        cout<<"What do you want to do with your matrix? 1 for transpose, 2 for multiply by number, 3 for summation, 4 for product, 5 for counting determiner"<<endl;
        cin>>sel;
        if(sel == 1){
        int**p=new int*[n];
        for(int i=0; i<n; i++) p[i] = new int[m];
            //cout <<"here"<<endl;
        TPN(M, p, m, n);
        for(int i=0; i<n; i++)
            {
            for(int j=0; j<m; j++)cout<<p[i][j]<<" ";
            cout<<endl;
            }
        }
        if(sel==2)
        {
            int k;
            cout<<"Enter the number by which the matrix will be multiplied with"<<endl;
            cin>>k;
            MLT(M, m, n, k);
            for(int i=0; i<m; i++)
            {
            for(int j=0; j<n; j++) cout<<M[i][j]<< " ";
            cout<<endl;
            }
        }
        if(sel==3)
        {
            cout<<"Now enter the matrix which will be added to your matrix"<<endl;
            int**N=new int*[m];
            for(int i=0; i<m; i++)N[i] = new int[n];
            create(N, m, n);
            int**p=new int*[m];
            for(int i=0; i<n; i++) p[i] = new int[n];
            cout<<"_______________________________________________"<<endl;
            SKL(M, N, p, m, n);
            for(int i=0; i<m; i++)
            {
            for(int j=0; j<n; j++)cout<<p[i][j]<<" ";
            cout<<endl;
            }
        }
        if(sel == 4)
        {
            cout<<"Enter the second value for the second matrix"<<endl;
            int k;
            cin>>k;
            int**N=new int*[n];
            for(int i=0; i<n; i++)N[i]=new int[k];
            create(N, n, k);
            int**p=new int*[m];
            for(int i=0; i<m; i++)p[i]=new int[k];
            cout<<"_______________________________________________"<<endl;
            PRD(M, N, p, m, n, k);
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<k; j++)cout<<p[i][j]<<" ";
                cout<<endl;
            }
        }
        if(sel == 5)
        {
            if(m!=n)cout<<"Your matrix should be quadratic (m=n). Cannot count determiner!!!"<<endl;
            else
            {
                int d=DET(M, m);
                cout<<"Your determiner is "<<d<<endl;
            }
        }
        cout<<"Here is your new matrix"<<endl;
        int c;
        cout<<"Do you want to continue? Press 1 for yes and 0 for no"<<endl;
        cin>>c;
        if(c==0)C=0;
    }
    return 0;
}



