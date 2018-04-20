#include<iostream>
#include<math.h>
using namespace std;

class Complex {
public:
    float real, imag;
    Complex(float r = 0, float i =0)
    {
        real = r;
        imag = i;
    }
    void suma(Complex,Complex);
    void produs(Complex,Complex);
    void modul(Complex);
    void impartire(Complex c1,Complex c2);
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    Complex operator * (Complex const &obj) {
         Complex res;
         res.real = real * obj.real;
         res.imag = imag * obj.imag;
         return res;
    }
    Complex(const Complex &c2)
    {
        real=c2.real;
        imag=c2.imag;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
    friend bool operator>(Complex c1,Complex c2);
    friend class Vector;
};
void Complex::suma(Complex c1,Complex c2)
{
    real=c1.real+c2.real;
    imag=c1.imag+c2.imag;
}

void Complex::produs(Complex c1,Complex c2)
{
    real=(c1.real*c2.real)-(c1.imag*c2.imag);
    imag=(c1.imag*c2.real)+(c1.real*c2.imag);
}

void Complex::modul(Complex c1)
{
    real=sqrt(c1.real*c1.real+c1.imag*c1.imag);
}

void Complex::impartire(Complex c1,Complex c2)
{
    if(c2.real*c2.real-c2.imag*c2.imag!=0)
    {
    Complex conj,a1,b1;
    conj.real=c2.real;
    conj.imag=-c2.imag;
    a1.real=(c1.real*conj.real)-(c1.imag*conj.imag);
    //cout<<a1.real<<endl;
    a1.imag=(c1.imag*conj.real)+(c1.real*conj.imag);
    //cout<<a1.imag<<endl;
    b1.real=(c2.real*c2.real)-(c2.imag*c2.imag);
    //cout<<b1.real<<endl;
    real=a1.real/b1.real;
    imag=a1.imag/b1.real;
    }
}
ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out <<" + "<<c.imag<<"i  ";
    return out;
}

bool operator >(Complex c1,Complex c2)
{
    return c1.real>c2.real;
}
istream & operator >> (istream &in,  Complex &c)
{
    in>>c.real;
    in>>c.imag;
}
class Vector
{
    private:
        Complex *v;
        int n;
    public:
         Vector(void);
         Vector(int,Complex*);
        ~Vector();
        Complex &operator[] (int index);
        int Size();
        void suma_m(Complex c2,Complex c1);
};
    Vector::Vector(void){
}
    Vector::Vector(int l,Complex *nr)
    {
        n=l;
        v=new Complex[n];
        for(int i=0;i<n;i++)
            v[i]=nr[i];
    }
    Vector::~Vector()
    {
        delete[]v;
    }
    Complex &Vector::operator[](int index)
    {
        return v[index];
    }
    /*void Vector::Vector(Complex c1,Complex c2)
    {

    }*/

int main()
{
    Complex c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12;
    cout<<"suma,produsul,impartirea a doua numere complexe si modulul primului dintre ele:"<<endl<<endl;
    cout<<"introduceti partea reala si cea imaginara a primul element: ";
    cin>>c1;
    cout<<"introduceti partea reala si cea imaginara a celui de-al doilea element: ";
    cin>>c2;
    c3.suma(c1,c2);
    c4.produs(c1,c2);
    c5.modul(c1);
    c6.impartire(c1,c2);
    cout<<"suma =: "<<c3<<endl;
    cout<<"produs =: "<<c4<<endl;
    cout<<"modulul lui c1=: "<<c5.real<<endl;
    if(c2.real*c2.real-c2.imag*c2.imag==0)
        cout<<"Impartirea nu se poate efectua"<<endl;
    else
        cout<<"Impartire =: "<<c6<<endl;
    Complex  *numere,*numere2;
    int n,i;
    float a,b;
    cout<<"Cate numere sa fie in cei doi vectori: "<<endl;
    cin>>n;
    numere=new Complex[n];
    numere2=new Complex[n];
    cout<<"Introduceti partea reala si cea imaginara a elementelor primului vector"<<endl;
    for(i=0;i<n;i++)
        {
            cin>>a>>b;
            numere[i]=Complex(a,b);
        }
    cout<<"Introduceti partea reala si cea imaginara a celui de-al doilea vector"<<endl;
    for(i=0;i<n;i++)
        {
            cin>>a>>b;
            numere2[i]=Complex(a,b);
        }
    cout<<"primul vector este format din numerele urmatoare: "<<endl;
    int j,k;
    for(j=0;j<n;j++)
        cout<<numere[j]<<endl;
    cout<<"al doilea vector este format din numerele urmatoare: "<<endl;
    for(j=0;j<n;j++)
        cout<<numere2[j]<<endl;
    cout<<"Vectorul de module din primul vector este: ";
    for(j=0;j<n;j++)
    {
          c8.modul(numere[j]);
          cout<<c8.real<<' ';
          c7.suma(numere[j],c7);
          c9.produs(numere2[j],numere[j]);
          c10.suma(c9,c10);
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n-1;k++)
        {
            c11.modul(numere[k]);
            c12.modul(numere[k+1]);
            //cout<<endl<<c11.real<<' '<<c12.real;
            if(c11>c12)
            {
                Complex man;
                man.real=numere[k].real;
                numere[k].real=numere[k+1].real;
                numere[k+1].real=man.real;
                man.imag=numere[k].imag;
                numere[k].imag=numere[k+1].imag;
                numere[k+1].imag=man.imag;
            }
        }
    }
    cout<<endl<<"suma tuturor elementelor din primul vector este: "<<c7<<endl;
    cout<<"produsul scalar a celor doi vectori este: "<<c10<<endl;
    cout<<"vectorul sortat dupa module este: "<<endl;
    for(j=0;j<n;j++)
    {
        cout<<numere[j]<<' ';
    }
}
