/*Quiz 1
Instituto Tecnologico de Costa Rica.
Melany Dahiana Salas Fernandez.
Carné: 2021121147
*/

//LIBRERIAS---------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

enum tipoMedia {video, audio, foto};

//ESTRUCTURAS-------------------------------------------------------------------------------------------------------------------------
struct Media{
    string url;
    tipoMedia type;
};

//CLASES------------------------------------------------------------------------------------------------------------------------------
//____________________________________________________________________________________________________________________________________
//Clase Noticia
//Atributos: titulo, fecha y reportero
class TNoticia {
    protected:
        string title;
        string fecha;
        string reportero;
    
    public:
        //Constructor
        TNoticia(){};

        TNoticia( string nTitle, string nFecha, string nReportero){
            title = nTitle;
            fecha = nFecha;
            reportero = nReportero;
        };

        // SETS Y GETS
        void setTitle( string nTitle){
            title = nTitle;
        }

        string getTitle(){
            return title;
        }

        void setFecha( string nFecha){
            fecha = nFecha;
        }

        string getFecha(){
            return fecha;
        }
        
        void setReportero( string nReportero){
            reportero = nReportero;
        }

        string getReportero(){
            return reportero;
        }
        
        //Metodo ToString()
        //void getInfo(){
        //    cout << "Titulo: " << title << " Fecha: " << fecha << " Reportero: " << reportero<<endl;
       // }
        virtual void getInfo(){};

} ;



//____________________________________________________________________________________________________________________________________
//Clase Noticia paper
//Hereda de clase noticia
//Atributos: Ruta a archivo para la foto y los que hereda de la clase madre
class TnoticiaPaper : public TNoticia {
    private:
        string linkFoto;
    public:
        
        TnoticiaPaper(string nTitle, string nFecha, string nReportero, string nLink): TNoticia(nTitle,nFecha,nReportero){
            linkFoto = nLink;
        }

        //SETTERS Y GETTERS
        void setLink(string nLink){
            linkFoto = nLink;
        }

        string getLink(){
            return linkFoto;
        }

        //Metodo toString
        void getInfo(){
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tLink: " << linkFoto <<endl;
        }

};

//____________________________________________________________________________________________________________________________________
//Clase Noticia paper
//Hereda de clase noticia
//Atributos: Ruta a archivo para la foto y los que hereda de la clase madre
class TnoticiaRadio : public TNoticia {
    private:
        string linkAudio;
    public:
        
        TnoticiaRadio(string nTitle, string nFecha, string nReportero, string nLink): TNoticia(nTitle,nFecha,nReportero){
            linkAudio = nLink;
        }

        //SETTERS Y GETTERS
        void setLink(string nLink){
            linkAudio = nLink;
        }

        string getLink(){
            return linkAudio;
        }

        //Metodo toString
        void getInfo(){
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tLink para Audio: " << linkAudio <<endl;
            
        }

};

//____________________________________________________________________________________________________________________________________
//Clase Noticia paper
//Hereda de clase noticia
//Atributos: Ruta a archivo para la foto y los que hereda de la clase madre
class TnoticiaDigital : public TNoticia {
    private:
        vector<Media> media;
    public:
        
        TnoticiaDigital(string nTitle, string nFecha, string nReportero, vector<Media> nMedia): TNoticia(nTitle,nFecha,nReportero){
            media = nMedia;
        }

        //SETTERS Y GETTERS
        void setLink(vector<Media> nMedia){
            media = nMedia;
        }

        vector<Media> getMedia(){
            return media;
        }

        //Metodo para agregar media a la noticia
        void agregarMedia(string url_media, tipoMedia type){
            Media newMedia;
            newMedia.type = type;
            newMedia.url = url_media;
            media.push_back(newMedia);
        }

        //Metodo toString
        void getInfo(){
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tMedia: \n";
            for(int i = 0; i< media.size(); i++){
                cout<< "\t\tTipo: ";
                if( media[i].type == 0){
                    cout << "Video";
                } else if(media[i].type == 1){
                    cout << "Audio";
                } else
                    cout << "Foto";
                cout << "\tDireccion URL: "  << media[i].url << endl;
            }
        }

};


//FUNCIONES-------------------------------------------------------------------------------------------------------------------------
//Funcion para agregar noticias al vector
//Entradas: Recibe una notica de tipo TNoticia por valor y un adminNoticias por referencia 
//Salidas: None
void agregarNoticias(TNoticia noticia, vector<TNoticia> &adminNoticias ){
    int lim = adminNoticias.size();
    adminNoticias.push_back(noticia);
}

//Metodo para agregar media a la noticia
vector<Media> agregarMedia(vector<Media> media, string url_media, tipoMedia type){
    Media newMedia;
    newMedia.type = type;
    newMedia.url = url_media;
    media.push_back(newMedia);
    return media;
}

//MAIN-------------------------------------------------------------------------------------------------------------------------------

int main(){
    //vector para media de noticias digitales
    vector<Media> mediaP;

    //Vector para almacenar los objetos 
    vector<TNoticia*> adminNoticias;

    //Instaciaciones y llamados a constructores----------------------------------------------------------------------------------------------------

    //Creacion del objeto de tipo Noticia Paper
    TnoticiaPaper noticia1("El caos en la vacunación multiplica las renuncias por miedo", \
    "10/04/2021", "El Mundo", "https://e00-elmundo.uecdn.es/assets/multimedia/imagenes/2021/04/09/16180028369004.png");

    //Creacion del objeto de tipo Noticia Radio
    TnoticiaRadio noticia2("Fin de semana violento: 10 personas fueron asesinadas", "28/2/2022", "Dudly Lynch",\
     "https://www.teletica.com/sucesos/fin-de-semana-violento-10-personas-fueron-asesinadas_306340");

    //Creacion del objeto de tipo Noticia Digital
    mediaP= agregarMedia(mediaP, "https://ichef.bbci.co.uk/news/800/cpsprodpb/1795F/production/_123470669_mediaitem123462618.jpg.webp", foto);
    mediaP= agregarMedia(mediaP, "https://ichef.bbci.co.uk/news/800/cpsprodpb/E107/production/_123470675_gettyimages-1238846907.jpg.webp", foto);
    TnoticiaDigital noticia3("Rusia invade Ucrania: el cerco ruso se estrecha sobre Kiev donde el ataque a una torre de TV deja 5 muertos", \
    "01/03/2022", "BBC News Mundo", mediaP);

    adminNoticias={&noticia1,&noticia2};
    adminNoticias.push_back(&noticia3);
 

   cout<< "Noticias en la lista de noticias: "<< endl;
    for(int i=0; i < adminNoticias.size(); i++){
        adminNoticias[i]->getInfo();
        cout<<"\n";
    } 

    for(int i2 = adminNoticias.size()-1; i2 >= 0; i2--){
        delete(adminNoticias[i2]);
    }

    return 0;
}