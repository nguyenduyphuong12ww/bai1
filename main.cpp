#include <iostream>

using namespace std;


struct PhanSo
{
    int TuSo;
    int MauSo;
};
//Cau 1:
void Nhap(PhanSo &a)
{
    cout<<"Nhap tu::"<<endl;
    cin>>a.TuSo;
    cout<<endl<<"Nhap mau:"<<endl;
    cin>>a.MauSo;
}

//Cau 2:
void Xuat(PhanSo a)
{
    cout<<a.TuSo<<"/"<<a.MauSo<<endl;
}
/*Cau 3: Rút gọn phân số

    Input :
        + Phân số b => Đặt ()

    Output:
        +Phân số kết quả => return
*/

int TimUCLN(PhanSo b)
{
    int x=b.TuSo;
    int y=b.MauSo;
    while (x!=0&&y!=0)
    {
        if(x>=y)
        {
            x=x-y;
        }
        else
        {
            y=y-x;
        }
    }
    return x+y;
}

PhanSo RutGon (PhanSo &b)
{
    PhanSo kq;

    kq.TuSo=b.TuSo;
    kq.MauSo=b.MauSo;

    kq.MauSo/=TimUCLN(b);
    kq.TuSo/=TimUCLN(b);

    return kq;
}
/*Câu 4 : So sánh 2 phân số
Input :
    + Phân số c => Đặt ()
    + Phân số d => Đặt ()
Output :
    + -1 (c<d), 1 (c>d), 0 (c=d) => return int
*/

int SoSanh (PhanSo c,PhanSo d)
{
    double x,y;
    x=(c.TuSo*1.0/c.MauSo);
    y=(d.TuSo*1.0/d.MauSo);
    if(x>y)
        return 1;
    else if(x<y)
        return -1;
    else if(x==y)
        return 0;

}

/*Câu 5 : Cộng 2 phân số
Input :
    +Phân số x => Đặt ()
    +Phân số y => Đặt ()
Output :
    +Phân số cộng => return PhanSo
*/

PhanSo Cong (PhanSo x,PhanSo y)
{
    PhanSo kq;
    kq.TuSo=x.TuSo*y.MauSo+x.MauSo*y.TuSo;
    kq.MauSo=x.MauSo*y.MauSo;
    return kq;
}

/*Câu 6 : Trừ 2 phân số
Input :
    + Phân số e => Đặt ()
    + Phân số g => Đặt ()
Output :
    + Phân số trừ  => return PhanSo
*/

PhanSo Tru (PhanSo e,PhanSo g)
{
    PhanSo kq;
    kq.TuSo=e.TuSo*g.MauSo-e.MauSo*g.TuSo;
    kq.MauSo=e.MauSo*g.MauSo;
    return kq;
}

/*Câu 7 : Nhân 2 phân số
Input :
    + Phân số h => Đặt ()
    + Phân số i => Đặt ()
Output :
    + Phân số nhân  => return PhanSo
*/

PhanSo Nhan (PhanSo h,PhanSo i)
{
    PhanSo kq;
    kq.TuSo=h.TuSo*i.TuSo;
    kq.MauSo=h.MauSo*i.MauSo;
    return kq;
}

/*Câu 8 : Chia 2 phân số
Input :
    + Phân số j => Đặt ()
    + Phân số k => Đặt ()
Output :
    + Phân số chia  => return PhanSo
*/

PhanSo Chia (PhanSo j,PhanSo k)
{
    PhanSo kq;
    kq.TuSo=j.TuSo*k.MauSo;
    kq.MauSo=j.MauSo*k.TuSo;
    return kq;
}


/* Câu 9 : Tìm phân số lớn nhất
Input :
    +PhanSo f[] => Đặt ()
    +int n
Output :
    +return PhanSo lớn nhất
*/

PhanSo timPS (PhanSo f[],int n)
{
    PhanSo m = f[0];
    for(int i = 1;i<n;i++)
    {
        if(SoSanh (f[i],m)==1)
            m=f[i];
    }
    return m;
}

int main()
{
    PhanSo a ={5,6};


    cout<<"Cau 2:"<<endl;
    cout<<"Xuat phan so:";

    Xuat (a);

    cout<<"Cau 3:"<<endl;

    PhanSo b={12,8};

    cout<<"Phan so da duoc rut gon:";

    Xuat (RutGon(b));

    cout<<"Cau 4:"<<endl;

    PhanSo c={1,5};
    PhanSo d={2,9};

    cout<<"Ket qua so sanh:";
    cout<<SoSanh (c,d)<<endl;

    cout<<"Cau 5:"<<endl;
    PhanSo x ={4,5};
    PhanSo y ={3,7};

    cout<<"Ket qua phep cong :";
    Xuat (Cong (x,y));

    cout<<"Cau 6:"<<endl;
    PhanSo e ={11,3};
    PhanSo g ={5,8};

    cout<<"Ket qua phep tru :";
    Xuat (Tru (e,g));

    cout<<"Cau 7:"<<endl;
    PhanSo h ={1,9};
    PhanSo i ={8,3};

    cout<<"Ket qua phep nhan :";
    Xuat (Nhan (h,i));

    cout<<"Cau 8:"<<endl;
    PhanSo j ={2,7};
    PhanSo k ={4,3};

    cout<<"Ket qua phep chia :";
    Xuat (Chia (j,k));




    cout<<"Cau 9:"<<endl;

    int n=3;
    PhanSo f[n];
    f[0]={1,2};
    f[1]={3,4};
    f[2]={3,7};

    cout<<"Phan so lon nhat:";
    Xuat (timPS(f,n));





    return 0;
}
