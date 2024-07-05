#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int output;
string choice;
string username,check_username;
class reg
{
    string name,mail,gender,username,pass,mobile;
public:
    reg (  string name,string mail,string gender,string username,string pass,string mobile)
    {
        this->name=name;
        this->mail=mail;
        this->gender=gender;
        this->username=username;
        this->pass=pass;
        this->mobile=mobile;
    }
    void file_write()
    {
        ofstream fout;
        fout.open("register.txt",std::ios_base::app);
        fout<<"User_name : "<<username<<endl;
        fout<<"Password : "<<pass<<endl;
        fout<<"Name : "<<name<<endl;
        fout<<"Email : "<<mail<<endl;
        fout<<"Gender : "<<gender<<endl;
        fout<<"Mobile : "<<mobile<<endl<<endl;
        fout.close();
    }
};
class login
{
    string c_uname,c_pass;
public:
    login(string c_uname,string c_pass)
    {
        this->c_uname=c_uname;
        this->c_pass=c_pass;
    }
    int find_id()
    {
        string input;
        int a=0,b=0,i=1,result;
        ifstream fin;
        fin.open("register.txt");
        while(!fin.eof()) //fin jotokhon sesh porjnto na jay
        {
            fin>>input;
            if(input==c_uname) a=i;
            if(input==c_pass) b=i;
            if(b-a==3) break; //more than 1jon user er pass same holeo jate somossa na hoy
            i++;
        }
        if(a==0)  result=a;
        else if(a!=0 && b-a!=3) result=-1;
        else if(a!=0 && b-a==3) result= a;
        return result;
        fin.close();

    }
    void set_mypage(int);
};
void login::set_mypage(int index)
{
    int j=1,k=1;
    bool inc_index=false;
    string item;
    ofstream outf;
    ifstream fin;
    outf.open("mylogin.txt");
    fin.open("register.txt");
    while(!fin.eof())
    {
        fin>>item;
        if(j==index-2)
        {
            outf<<item<<" ";
            if(j%3==0) outf<<endl;
            inc_index=true;
            k++;

        }
        j++;
        if(inc_index) index++;
        if(k==19) break;

    }
    outf.close();
    fin.close();

}
class second_page
{

public:

    virtual void show()
    {}

    virtual void display() {}

};
class schedule : public second_page
{
public:
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"SCHEDULES : "<<endl<<endl;
        cout<<"Tuesday to Saturday-- \n-Morning shift 1:-10am to 11am \n-Morning shift 2:-11am to 12pm \n-Evening shift 1:-5.30pm to 6.30pm \n-Evening shift 2:-7pm to 8pm"<<endl;
    }
};
class facilities : public second_page
{
public:
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"In Workout Zone-we are providing : \n-Special Workout Equipments \n-Experieced Dietatian for Guidelining \n-Protien Shake corner \n-Excercising Gloves"<<endl;
        cout<<"Expert Trainers \n-Yoga Mates for Free Hand Exercises \n-Sauna Bath Corner \n-Affordable Membership Plan(In main menu-press 3) "<<endl;
    }

};
class membership_p :public second_page
{
public:
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"Monthly Plan- "<<endl;
        cout<<"\t2000TK(with Trademill)"<<endl;
        cout<<"\t1500TK(without Trademill)"<<endl;
        cout<<"3 Months Plan-"<<endl;
        cout<<"\t5000TK(with Trademill)"<<endl;
        cout<<"\t4000TK(without Trademill)"<<endl;
        cout<<"6 Months Plan-"<<endl;
        cout<<"\t10000TK(with Trademill)"<<endl;
        cout<<"\t8500TK(without Trademill)"<<endl;
        cout<<"Yearly Plan-"<<endl;
        cout<<"\t20000TK(with Trademill)"<<endl;
        cout<<"\t17000TK(without Trademill)"<<endl;
    }
};
class workout_av: public second_page
{
public:
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"For Muscle Building-"<<endl;
        cout<<"\tWeight Lifting- \n\t\tDumbles(500gm/1kg/2kg/4kg)"<<endl;
        cout<<"\t\tBarbell set \n\t\tPower Case"<<endl;
        cout<<"For Cardio-"<<endl;
        cout<<"\tTrademill \n\tStair Mill \n\tRecumbent Exercise Bike \n\tStationary Bicycle \n\tSpin Bike"<<endl;
    }


};
class payment
{
protected:
    int paym;
public:
    payment(int paym)
    {
        this->paym=paym;
    }
    payment()
    {}
    void show_payment()
    {
        cout<<paym<<" ";
    }
};
class mentors: public second_page,public payment
{
public:
    mentors(int x):payment(x)
    {}
    mentors():payment()
    {}
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"Premium- \n\tMakit Ahsan Abir \n\tRiyad Adnan \n\tRashid Riya Urmi \n\tAmit Paul \n\tSamira Khan \n\tAbonty Rahman"<<endl;
        cout<<"Normal- \n\tMarzan Kotha \n\tIsmail Emon \n\tArpita Debnath \n\tAmrita Sen \n\tZaveed Khan \n\tRafee Islam \n\tMrinmoy Mahin \n\tSahin Zamal"<<endl;
    }


};
class personal_info:public second_page
{
    void show()
    {
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"(1) Schedule \n(2) Facilities \n(3) Membership Plan \n(4) Workout Availabilities \n(5) Mentors \n(6) Personal Info \n";
    }
    void display()
    {
        int k=1;
        ifstream fin;
        string details;
        fin.open("mylogin.txt");
        while(!fin.eof())
        {
            fin>>details;
            cout<<details;
            if(k%3==0) cout<<endl;
            details.clear();
            k++;
        }

    }
};
int find_username(string name)
{
    ifstream fin;
    string usercheck;
    fin.open("register.txt");
    while(!fin.eof())
    {
        fin>>usercheck;
        if(usercheck==name) return 1;

    }
    fin.close();
    return 0;
}
int _member(string name)
{
    string membercheck;
    ifstream fin;
    fin.open("memberlist.txt");
    while(!fin.eof())
    {
        fin>>membercheck;
        if(membercheck==name) return true;

    }
    fin.close();
    return false;

}
class verify
{
    int s_code=121212,sent_code;
public:
    void set_code(int sent_code)
    {
        this->sent_code=sent_code;
    }
    void operator+()
    {
        sent_code=-sent_code;

    }
    bool final_result()
    {
        if((s_code+sent_code)==0) return true;
        else return false;
    }

};
void _member()
{
    ofstream fout;
    fout.open("memberlist.txt",std::ios_base::app);
    fout<<check_username<<endl;
    fout.close();
}

int main()
{
start:
    system("CLS");
    cout<<"..............................................Welcome To -The Workout Zone.......................................\n\n"<<endl;
    cout<<"Please Enter Your Choice    :   \n(1) Register \n(2) Login"<<endl;
start_page:
    cin>>choice;
    if(choice=="1")
    {

        string na,mail, gen,pass="",mob;
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"You Have Chosen Register-"<<endl;
        cout<<"For Registration- \n\nEnter Your Information : \n***PLEASE DON'T USE ANY SPACE WHILE GIVING INFORMATION"<<endl;

        cout<<"Name : ";
        cin>>na;
        cout<<"Email : ";
        cin>>mail;
        cout<<"Gender : ";
        cin>>gen;
user_name:
        cout<<"User_name : ";
        cin>>username;
        if(find_username(username))
        {
            cout<<"This Username is Already Taken.Try Anything Else"<<endl;
            goto user_name;
        }
        cout<<"Password : ";
        char ch=_getch();
        while(ch!=13)
        {
            pass.push_back(ch);
            cout<<"*";
            ch=_getch();
        }

        cout<<"\nMobile : ";
        cin>>mob;
        reg r( na,mail,gen,username,pass,mob);
        r.file_write();
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"Registration Complete.Press 2 For Login"<<endl;
        goto start_page;
    }

    else if(choice=="2")
    {
        string check_pass="";
        system("CLS");
        cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
        cout<<"For Login-\n\nEnter Your Username : "<<endl;
        cin>>check_username;
start_page_1:
        cout<<"Enter Your Password : "<<endl;
        char ch=_getch();
        while(ch!=13)
        {
            check_pass.push_back(ch);
            cout<<"*";
            ch=_getch();
        }
        login L(check_username,check_pass);
        output= L.find_id();
        if(output==0)
        {
            system("CLS");
            cout<<"User ID not found"<<endl;
            cout<<"Don't have any account? \n\tPress 1 for register \n\tPress 2 for login"<<endl;
            goto start_page;
        }
        else if(output==-1)
        {
            system("CLS");
            cout<<"Incorrect Password\nTry Again\n"<<endl;
label:
            cout<<"Press 0 to go back "<<endl;
            cout<<"Press 1 to Exit "<<endl;
            cin>>choice;
            if(choice=="0")
                goto start_page_1;
            else if(choice=="1")
                goto start;
            else
            {
                system("CLS");
                cout<<"You Didn't Press the right key"<<endl;
                goto label;
            }
        }
        else
        {
            system("CLS");
            cout<<"Login Successful"<<endl<<endl<<endl;
            L.set_mypage(output);
            goto second_step;
        }

    }
    else
    {
        cout<<"Please select the right option"<<endl;
        goto start_page;
    }
second_step:
    second_page *lists[6];
    schedule sch;
    facilities fac;
    membership_p mp;
    workout_av wav;
    mentors ment;
    personal_info pi;
    lists[0]=&sch;
    lists[1]=&fac;
    lists[2]=&mp;
    lists[3]=&wav;
    lists[4]=&ment;
    lists[5]=&pi;
    cout<<".........................................Welcome To -The Workout Zone......................................\n\n"<<endl;
    cout<<"(1) Schedule\n(2) Facilities\n(3) Membership Plan\n(4) Workout Availabilities\n(5) Mentors\n(6) Personal Info\n";
second_choice:
    cout<<"Enter Your Choice : ";
    cin>>choice;
    if(choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5" && choice!="6")
    {
        system("CLS");
        cout<<"Please select the right option"<<endl;
        goto  second_choice;
    }
    if(choice =="1")
    {
        lists[0]->display();
schedule:
        cout<<"\nPress any key for Back to Main Menu : ";
        cin>>choice;
        if(choice>="0" && choice<="9")
        {
            lists[0]->show();
            goto second_choice;
        }
        else
        {
            cout<<"Please press any digit between 0-9"<<endl;
            goto schedule;
        }
    }
    else if(choice=="2")
    {
        lists[1]->display();
facilities:
        cout<<"\nPress any key for Back to Main Menu : ";
        cin>>choice;
        if(choice>="0" && choice<="9")
        {
            lists[1]->show();
            goto second_choice;
        }
        else
        {
            cout<<"Please press any digit between 0-9"<<endl;
            goto facilities;
        }
    }
    else if(choice=="3")
    {
        lists[2]->display();
m_plan:
        cout<<"\nPress any key for Back to Main Menu : ";
        cin>>choice;
        if(choice>="0" && choice<="9")

        {
            lists[2]->show();
            goto second_choice;
        }
        else
        {
            cout<<"Please press any digit between 0-9"<<endl;
            goto m_plan;
        }
    }
    else if(choice=="4")
    {
        lists[3]->display();
workout_eqp:
        cout<<"\nPress any key for Back to Main Menu : ";
        cin>>choice;
        if(choice>="0" && choice<="9")
        {
            lists[3]->show();
            goto second_choice;
        }
        else
        {
            cout<<"Please press any digit between 0-9"<<endl;
            goto workout_eqp;
        }

    }
    else if(choice=="5")
    {
        lists[4]->display();
        mentors p_payment(15000),n_payment(12000);
        cout<<"Premium payment-";
        p_payment.show_payment();
        cout<<"For 12week mentorship"<<endl;
        cout<<"Normal payment-";
        n_payment.show_payment();
        cout<<"For 12week mentorship"<<endl;

mentor:
        cout<<"\nPress any key for Back to Main Menu : ";
        cin>>choice;
        if(choice>="0" && choice<="9")
        {
            lists[4]->show();
            goto second_choice;
        }
        else
        {
            cout<<"Please press any digit between 0-9"<<endl;
            goto mentor;
        }

    }
    else if(choice=="6")
    {
info:
        system("CLS");
        cout<<"\nYour Information : "<<endl<<endl;
        lists[5]->display();
        cout<<"\n\nWant To Apply For Membership? \n\tPress 1"<<endl;
        cout<<"\nPress 2 for Logout\n";
        cout<<"\nPress 0 for Back to Main Menu : ";

personal_info_part:
        cin>>choice;
        if(choice=="0")
        {
            lists[5]->show();
            goto second_choice;
        }
        else if(choice=="2") goto start;
        else if(choice=="1" )
        {
            if(_member(check_username))
            {
                system("CLS");
                cout<<"\n\nYou Are Already a Member of THE WORKOUT ZONE"<<endl;
                cout<<"Press any key to go Back"<<endl;
                cin>>choice;
                goto info;

            }
            else
            {
                int se_code;
                system("CLS");
                cout<<"\n\nOur Contact no. 01715652049"<<endl;
                cout<<"Please contact with us and after completing the procedure of being a member,Enter the security code we have sent you"<<endl;
code:
                cout<<"CODE : ";
                cin>>se_code;
                verify v,check_v;
                v.set_code(se_code);
                +v;
                bool ab;
                ab=v.final_result();
                if(ab)
                {
                    system("CLS");
                    cout<<"\n\nYour Membership Confirmed Successfully.You are a verified member now"<<endl;
                    _member();
                    cout<<"Press any key to go back"<<endl;
                    cin>>choice;
                    goto info;
                }
                else
                {
                    system("CLS");
                    cout<<"\n\nIncorrect security code"<<endl;
                    cout<<"Press any other Key to go back"<<endl;
                    cout<<"For Trying again - Press 1"<<endl;
                    cin>>choice;
                    if(choice=="1") goto code;
                    else goto info;
                }
            }
        }
        else
        {
            cout<<"Choose The Right Option"<<endl;
            goto personal_info_part;
        }
    }
}
