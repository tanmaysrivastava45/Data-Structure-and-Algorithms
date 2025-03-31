// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     switch(n)
//     {
//         case (1):cout<<"hello guise"<<endl;
//         break;

//         case (2): cout<<"namaste sabhi ko"<<endl;
//          break;

//         default : cout<<"kya bol rha hai bhai "<<endl;
//     }
// }
//------------------------------------------------------------------------------------------------\\/
//homework
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n=1;
//     while(1)
//     {
//         switch(n)
//         {
//          case (1):cout<<"radhe radhe";
//          break;
//         }
//         exit(n);  // used to get exit from infinite loop
//     }
// }

//----------------------------------------------------------------------------------------------\/
//homework

// #include<iostream>
// using namespace std;
// int main()
// {

 
//     for(int i=0;i<=10;i++)
//     {
//        if( i%2==0)
//        {
//         continue;}  // continue does not work in switch case 
//       cout<<i; 
//     }
    

// }
//------------------------------------------------------------------------------------------\/
// homework mini calculator

// #include<iostream>
// using namespace std;
// int main()
// {
//     int a, b;
//     char ch;
//     cout<< "enter the value of a "<<endl;
//     cin>>a;

//     cout<<"enter the value of b "<<endl;
//     cin>>b;

//     cout<<"enter the operand "<<endl;
//     cin>>ch;

    
//     switch(ch)
//     {
//         case ('+'): cout<<a+b;
//         break;
//         case ('-'): cout<<a-b;
//         break;
//         case ('*'): cout<<a*b;
//         break;
//         case('/'):cout<<a/b;
//         break;

//         default:cout<<"enter valid operand";
//     }
// }

//------------------------------------------------------------------------\/

//homework

#include<iostream>
using namespace std;
int main()
{
    int amount;
    cout<<"enter the amount "<<endl;
    cin>>amount;
    int note=0;
    int num=1;
    switch(num)
    {
        case 1:{
            note=amount/100;
            amount = amount - (100*note);
            cout<<"number of 100Rs note required "<<note<<endl;
        }
        case 2:{
            note=amount/50;
            amount = amount - (50*note);
            cout <<"number of 50Rs note required "<<note<<endl;
        }
        case 3: {
            note= amount/20;
            amount= amount - (20*note);
            cout<<"number of 20Rs note required "<<note<<endl;
        }
        case 4:
        {
            note=amount/1;
            amount = amount - (1*note);
            cout<<"number of 1Rs note required "<<note<<endl;
        }

    }
}