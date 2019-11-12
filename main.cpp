#include <iostream>

#include <gmp.h>
#include <gmpxx.h>
#include "stdio.h"
using namespace std;

int main()
{
    cout << "GMP TEST BEGIN!" << endl;
    int limb_size=sizeof(mp_limb_t);
    cout<<"the size of limb is "<<limb_size*8<<" bits"<<endl;

    FILE *fp;
    //fp=fopen("test.txt","at+");
    mpz_t aaa,bbb,ccc;
    mpz_init(aaa);
    mpz_init2 (bbb,256);
    mpz_random (bbb,4);

    mpz_init2(ccc,64);
    mpz_random(ccc,1);
    //mpz_out_str(fp,10,bbb);   //test.txt中45911199988959465183765912664616310275170336168741130658429954235029908138100
    gmp_printf ("%s is an mpz %Zd\n", "here", bbb);//取出256位随机数
    //的带一个limb指针
    const mp_limb_t *pre;
    mp_size_t nnnn=mpz_size(bbb);
    pre=mpz_limbs_read(bbb);
    gmp_printf("limb array is  %Nd\n ",pre,nnnn);
    gmp_printf ("%s is an ccc %Zd\n", "here", ccc);
///
    //得到一个limb数
    const mp_limb_t *modd;
    modd=mpz_limbs_read(ccc);
    mp_limb_t modd1=*modd;
    gmp_printf("modd1  is  %Md\n ",modd1);
///
    mp_limb_t anws;
    anws=mpn_mod_1(pre,4,modd1);
    gmp_printf("anws is  %Md\n ",anws);
//验证
    mpz_t ddd;
    mpz_init2(ddd,64);
    mpz_mod(ddd, bbb, ccc);
    gmp_printf("test mod is %Zd\n",ddd);

    //cout<<"the size of limb is "<<aaa<<" bits"<<endl;
    /*
    绝对不能用cout，cout一用就错！！！！！
    */
    //mpz_out_str(fp,10,aaa);//fp为文件指针，10为进制代表，aaa为数
    //fclose(fp);
    //mp_limb_t num1=mpz_getlimbn (aaa,0);

    //mpz_out_str(fp,10,num1);//fp为文件指针，10为进制代表，aaa为数
    //mpz_out_str(fp,10,num1);//fp为文件指针，10为进制代表，aaa为数
    //fclose(fp);
    //const mp_limb_t *ptr;
    //gmp_printf ("limb array %Nx\n", ptr, 2);

}
