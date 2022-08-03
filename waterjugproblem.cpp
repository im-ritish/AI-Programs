#include<bits/stdc++.h>
using namespace std;
int x,y;
int min(int w, int z)
{
    return w < z ? w:z;
}

void show(int a, int b)
{
    cout << setw(12) << a << setw(12) << b << endl;
}

void s(int n, int m)
{
    int xq=0, yq=0;
    int t;
    cout << setw(15) <<"FIRST JUG"<< setw(15) <<"SECOND JUG"<<endl;
    while(xq != n && yq != n || xq != m && yq != m)
    {
        if(xq == 0){
            xq=x;
            show(xq,yq);
        }
        else if(yq == y){
            yq = 0;
            show(xq,yq);
        }
        else{
            t = min(y-yq,xq);
            yq = yq + t;
            xq = xq - t;
            show(xq,yq);
        }
    }
}


int main()
{
    int n,m;
    cout << "Enter the litres of water required out of the two jugs: ";
    cin >> n;
    cout << "Enter the litres of water required out of the two jugs: ";
    cin >> m;
    cout << "Enter the capacity of the first jug: ";
    cin >> x;
    cout << "Enter the capacity of the second jug: ";
    cin >> y;
    if(n<x || n<y)
    { 
        if(n%(__gcd(x,y))==0)
            s(n,m);
        else
            cout<<"This is not possible....\n";  
    }
    else{
        cout<<"This is not possible....\n";    
    }   
}