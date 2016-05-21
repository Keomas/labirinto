#include <iostream>
#include <fstream>

using namespace std;
ofstream out;
int lines=0;
int colunas=0;

struct ponto{
int line=0;
int coluna=0;  
  
  
};

bool x=true;
ponto ponto_inicial;
ponto ponto_anterior;
ponto ponto_atual;
//Pilha

class Pilha{
  
public:
  ponto pilha [10000];
  int topo=-1;
  int tmax=10000;
  
  void push(ponto p){
    
    if(topo <tmax-1 ){
    topo++;
    pilha[topo]=p;
    }
    else{
      
      cout<<"Pilha cheia"<<endl;
    }
    
  }
  
  ponto pop(){
    
    if(topo == -1){
      
      cout<<"Pilha vazia"<<endl;
      
    }else{
    ponto aux=pilha[topo];
    topo--;
    return aux;
    }
  }

  
  void quanti_itens(){
    
    cout<<topo+1<<endl;
    
    
  }
  
  void print_pilha(){
    int t=topo;
    for(t;t >=0; t--){
    cout<<pilha[t].coluna<<"  "<<pilha[t].line<<endl;  
      
      
      
    }
    
  }
  
  bool is_empty(){
    
    if(topo ==-1){
      
      return true;
    }else{
      return false;
    }
    
  }
  
  void zera_pilha(){
    
    topo=-1;
  }
  
};




char vetor [500][500];

void caminho_certo( char v[500] [500],Pilha &pi){
 bool aux=false;
 if(v[ponto_atual.line][ponto_atual.coluna+1]!='1'){
   
   ponto pnt=ponto_atual;
   pi.push(pnt);
   out<<"D ["<<ponto_atual.line<<","<<ponto_atual.coluna<<"]->["<<ponto_atual.line<<","<<ponto_atual.coluna+1<<"]"<<endl;
   v[ponto_atual.line][ponto_atual.coluna]='1';
   ponto_atual.coluna++;
   aux=true;
  
}else  if(v[ponto_atual.line-1][ponto_atual.coluna]!='1'){
   
   ponto pnt=ponto_atual;
   pi.push(pnt);
   out<<"F ["<<ponto_atual.line<<","<<ponto_atual.coluna<<"]->["<<ponto_atual.line-1<<","<<ponto_atual.coluna<<"]"<<endl;
   v[ponto_atual.line][ponto_atual.coluna]='1';
   ponto_atual.line--;
   aux=true;
   
   
}else
 if(v[ponto_atual.line][ponto_atual.coluna-1]!='1'){
   
   ponto pnt=ponto_atual;
   pi.push(pnt);
   out<<"E ["<<ponto_atual.line<<","<<ponto_atual.coluna<<"]->["<<ponto_atual.line<<","<<ponto_atual.coluna-1<<"]"<<endl;
   v[ponto_atual.line][ponto_atual.coluna]='1';
   ponto_atual.coluna--;
   aux=true;
   
}else if(v[ponto_atual.line+1][ponto_atual.coluna]!='1'){
   
   ponto pnt=ponto_atual;
   pi.push(pnt);
   out<<"T ["<<ponto_atual.line<<","<<ponto_atual.coluna<<"]->["<<ponto_atual.line+1<<","<<ponto_atual.coluna<<"]"<<endl;
   v[ponto_atual.line][ponto_atual.coluna]='1';
   ponto_atual.line++;
   aux=true;
  
   
}else{
  
  
}
 
x=aux;
 
}

bool achou_saida(){
  int lin=ponto_atual.line;
  int co=ponto_atual.coluna;
  
  if(((lin==0)||(lin==lines-1))  || ((co==0) || (co== colunas-1))){
    out<<"SAIDA ["<<ponto_atual.line<<","<<ponto_atual.coluna<<"]"<<endl;
    return true;
  }else{
    
    return false;
  }
  
  
}

void define_rota(char v [500] [500],Pilha &pi){
    
 while(!achou_saida()){ 
  if(x){
    
    caminho_certo(v,pi);
    
    
    
  }else{
    
      if(pi.is_empty()){
  
  out<<"SEM SAIDA"<<endl;
  break;
  
      }else{
  ponto_anterior=pi.pop();
  v[ponto_atual.line][ponto_atual.coluna]='1';
  out<<"BT ["<<ponto_anterior.line<<","<<ponto_anterior.coluna<<"]"<<"<-[";
  out<<ponto_atual.line<<","<<ponto_atual.coluna<<"]"<<endl;
  ponto_atual=ponto_anterior;
  caminho_certo(v,pi);
  
      }
    
    
  }
  
 }
  
  
}

void define_pontoinicial(char v [500] [500]){
  
  for(int j=0;j<lines;j++){
      for(int k=0;k<colunas;k++){
  
  if(vetor [j][k] =='X'){
    
   ponto_inicial.coluna=k;
   ponto_inicial.line=j;
  }
  
      }   
  }
  
  
} 

int main(int argc, char **argv) {
Pilha p;

  //-----------  
   out.open(argv[2]);
  ifstream input (argv[1]);
  //----------
 
   int nmatriz=0;
  input >>nmatriz;


  //lendo matriz
  for(int i =0; i<nmatriz;i++){
    
    input>>colunas>>lines;
    //cout<<colunas<<" "<<lines<<endl;
    for(int j=0;j<lines;j++){
      for(int k=0;k<colunas;k++){
  
  input >>vetor [j][k];
  
      }
    }
    
define_pontoinicial(vetor);
out<<"L"<<i<<":"<<endl;
out<<"INICIO ["<<ponto_inicial.line<<","<<ponto_inicial.coluna<<"]"<<endl;    

ponto_atual=ponto_inicial;
define_rota(vetor,p);  
p.zera_pilha();
x=true;
  
}
  
  input.close();
  out.close();
  
  return 0;

  
    
}
