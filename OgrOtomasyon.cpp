#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


//PROGRAM 1
struct ogrenciler{
        string No;
        string Ad;
        string Soyad;
        string Mail;
        string Telefon;
        string DogumTarihi;
        float Vize;
        float Odev;
        float Final;
};

struct veribasligi{
	
        string No;
        string Ad;
        string Soyad;
        string Mail;
        string Telefon;
        string DogumTarihi;
        string Vize;
        string Odev;
        string Final;
};

int idSayac;
int N ;
ogrenciler* s[200];
veribasligi* vb=new veribasligi;
ifstream input; 
fstream output;  
string next;
int secim;	
    	   
void GetirOgrenci(){
    

     	
       input.open("Ogrenciler.dat"); 
        if(input.is_open()==false){
        	cout<<"Ogrenciler.dat dosyasý bulunamadý.";
        	exit(0);
		}
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;

        
        input >> vb->No >> vb->Ad >> vb->Soyad >> vb->Mail >> vb->Telefon >>vb->DogumTarihi >> vb->Vize >> vb->Odev >> vb->Final;

        for(int i=0; i< N; i++){
                s[i] = new ogrenciler; 
                input >> s[i]->No >> s[i]->Ad >> s[i]->Soyad >> s[i]->Mail >> s[i]->Telefon >> s[i]->DogumTarihi >> s[i]->Vize >> s[i]->Odev >> s[i]->Final;
        }
        input.close();
        
}

void veribasligi(){
	
	
	  cout << vb->No <<" "<< vb->Ad <<" "<< vb->Soyad<<" " << vb->Mail <<" "<<vb->Telefon <<" "<<vb->DogumTarihi <<" "<< vb->Vize <<" "<< vb->Odev <<" "<< vb->Final<<endl; 
}

void ogrenciListele(){
	

    cout << "\n--------Tüm Bilgiler Listesi------------"<<endl;
    
    veribasligi();
	
	for(int i=0; i< N; i++){
                
	    
	    cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final << endl;
		
		}
	
}

void GNOHesapla(){
	
	cout << "\n\n----------------GNO Bilgileri Listesi---------------" <<endl;
        
        output.open("Kalanlar.txt",ios::out);
        output.close();
        output.open("Geçenler.txt",ios::out);
        output.close();
         for(int i=0; i< N; i++){
		      
              float gno= (0.3*s[i]->Vize + 0.2*s[i]->Odev + 0.5*s[i]->Final);
                
				if(gno<=46){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"FF" << " GNO :"<< gno <<" KALDI"<< endl;
					output.open("Kalanlar.txt",ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"FF" << " GNO :"<< gno <<" KALDI"<<"\n";
					output.close();
				}
				else if(gno>46&&gno<=49)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CD " << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CD " << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}	
				else if(gno>=50&&gno<=55)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CC " << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<<"CC "  << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
						else if(gno>=56&&gno<=60)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CB " << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CB " << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
					else if(gno>=61&&gno<=65)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BC " << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<<"BC "  << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
						else if(gno>=66&&gno<=70)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BB" << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BB" << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
					else if(gno>=77&gno<=83)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AB" << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AB" << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
				else if(gno>=84&gno<=100)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AA" << " GNO :"<< gno <<" GEÇTÝ"<<endl;
					output.open("Geçenler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AA" << "GNO :"<< gno <<" GEÇTÝ"<<"\n";
					output.close();
				}
				
        }
}
        		
void GNOKalan(){
	
		cout << "\n\n----------------Kalanlar Listesi---------------" <<endl;
        
         for(int i=0; i< N; i++){             
                 
              float gno= (0.3*s[i]->Vize + 0.2*s[i]->Odev + 0.5*s[i]->Final);
                
				if(gno<=46){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " FF " << " GNO :"<< gno <<" KALDI"<< endl;		
				}
				else if(gno>46&&gno<=49){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CD " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
				else if(gno>=50&&gno<=55){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CC "<< " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
				else if(gno>=56&&gno<=60){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CB " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
					else if(gno>=61&&gno<=65){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " BC " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
					else if(gno>=66&&gno<=70){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< "  BB " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
					else if(gno>=71&&gno<=76){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " BA " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
					else if(gno>=77&gno<=83){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " AB " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
					else if(gno>=84&gno<=100){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " AA " << " GNO :"<< gno <<" GEÇTÝ"<< endl;		
				}
				  	}
	
}
		
void veriEkle(){
	
	cout << " \n\n------------ Kayýt Ekleme ----------"<<endl;
	string data,out;
	cout << "Ad :";
    cin>>data;
    out=out+data+" ";
    cout << "Soyad :";
    cin>>data;
    out=out+data+" ";
    cout << "Mail :";
    cin>>data;
    out=out+data+" ";
    cout << "Telefon :";
    cin>>data;
    out=out+data+" ";
    cout << "Doðum Tarihi :";
    cin>>data;
    out=out+data+" ";
    cout << "Vize :";
    cin>>data;
    out=out+data+" ";
    cout << "Ödev :";
    cin>>data;
    out=out+data+" ";
    cout << "Final :";
    cin>>data;
    out=out+data;
    idSayac++;
    cout<<"Eklenen Veri : "<<idSayac<<" "<<out;
    output.open("Ogrenciler.dat" , ios::app);
	output<< "\n"<< idSayac <<" "<<out;
	output.close();
	output.open("counter.cr",ios::out);
    output<<idSayac;
    output.close();	
    N=idSayac;
}
		
void program1(){
	
	
        input.open("count.sy"); 
        if(input.is_open()){
     	
     	input>>idSayac;
     	N=idSayac;
     	input.close();
        }
     	else{
     		output.open("count.sy",ios::out);
     		output<<100;
     		output.close();
     		idSayac=100;
     		N=100;
     		
     	  }
		 
	GetirOgrenci();
	 cout << " \n\n------------ ÖÐRENCÝ OTOMASYONU ÝÞLEM MENÜSÜ ----------"<<endl;
      		cout << "Tüm Bilgileri Listele - 1"<<endl;
      		cout << "Notlarý Sonuçlandýr   - 2"<<endl;
      		cout << "Kalanlarý Gör         - 3"<<endl;
      		cout << "Kayýt Ekle            - 4"<<endl;
      		cout << "Seçiniz (1 - 2 - 3 - 4) : ";
      	    cin>>secim;
      	    
			  if(secim==1)
			  	  ogrenciListele();
		      else if(secim==2)
      	        GNOHesapla();
      	      else if(secim==3)
      	        GNOKalan();
      	      else if(secim==4)
      	       veriEkle();
      	        
		  
		 cout << "\nProgram Menüsüne Geri Dön - 1 / Çýkýþ - 2 :";
      	    cin>>secim;
      		
			  if(secim==1)	
      			program1();
      		  
	
}

//PROGRAM 1
//PROGRAM 2

int Rastgele(int max,int min , int adet){
	
	srand(time(0));
	float toplam=0,sayi;
	int sayilar[adet];
	
	for(int i = 0;i<adet;i++){	
	sayi= rand() % (max - min + 1) + min;
	sayilar[i]=sayi;
	toplam=sayi+toplam;
	cout<<sayi<<endl;
}
	float ortalama = toplam/adet;
	
	cout<<"Üretilen "<<adet << " adet sayýnýn ortalamasý "<<ortalama<<endl;
	
	cout<<"Dosyaya Kayýt Edilsin mi ? E/H ";
    char yanit;
	cin>>yanit;
	if(yanit=='E' || yanit=='e'){
		output.open("Rastgele.txt",ios::out);
		for(int i = 0;i<adet;i++){
     	output<<"Sayý "<<i<<" :"<<sayilar[i]<<"\n";
     	
		 }
		 output<<"Ortalamasý "<<ortalama;
		 output.close();
		
	}
	}
	
	
	


void sayiUretme(){
	
	int min , max,adet ;
	cout << " \n\n **Rastgele Sayý Üretme**"<<endl;	
	
     cout<<"Minimum Deðer Giriniz : ";
     cin>>min;
      cout<<"Maksimum Deðer Giriniz : ";
     cin>>max;
      cout<<"Adet Giriniz : ";
     cin>>adet;
     Rastgele(max,min,adet);
      
     
   	
}

void cikis(){
	
	cout << " \n\n------------ Çýkýþ ----------"<<endl;	

}


void kod2(){
	
	
	  cout<< " \n\n****Rastgele Sayý****"<<endl;
      	
		  
      		  
	
}

int main(void){
      
      setlocale(LC_ALL,"Turkish");
    
 
      	cout << "Hangi programa giriþ yapmak istiyorsunuz ?"<<endl;
      	cout << "Öðrenci Not Ýþlemleri / 1 - Rastgele Hesapmalama / 2 "<<endl;
      	cout << " Bir Seçim Yapýn : ";
      	cin>>secim;
      	
      	if(secim==1){
			program1();
				}		
		 else if (secim==2){
		kod2();	
		sayiUretme();
			
			 }
		


return 0;
}  
