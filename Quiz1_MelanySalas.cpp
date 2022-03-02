/*Quiz 1 y 2
Instituto Tecnológico de Costa Rica.
Melany Dahiana Salas Fernandez.
Carné: 2021121147
*/

//LIBRERIAS---------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

//ENUM PARA TIPOS DE MEDIA
enum tipoMedia {video, audio, foto};


//CLASES------------------------------------------------------------------------------------------------------------------------------
//____________________________________________________________________________________________________________________________________
//Clase TMedia
//Atributos: un url, un tipo e informacion adicional(puede ser autor, fechas, descripciones...)
class TMedia{
    private:
        string url;
        tipoMedia type;
        string infoAdicional;
    public:
        //Metodo constructor
        TMedia(string nUrl, tipoMedia nType, string nInfo){
            url = nUrl;
            type = nType;
            infoAdicional = nInfo;
        };

        //SETTERS Y GETTERS
        void setUrl(string nUrl){
            url = nUrl;
        }

        string getUrl(){
            return url;
        }

        void setType(tipoMedia ntype){
            type = ntype;
        }

        tipoMedia getType(){
            return type;
        }

        void setInfo(string nInfo){
            infoAdicional = nInfo;
        }

        string getInfo(){
            return infoAdicional;
        }

        void toString(){
            cout<< "\t\tTipo: ";
            if( type == 0){
                cout << "Video";
            } else if(type == 1){
                cout << "Audio";
            } else
                cout << "Foto";
            cout << "\tDireccion URL: "  << url << "\n\t\t\tInformacion Adicional: " << infoAdicional<< endl;
        }

};

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

        //Costructor sobrecargado
        TNoticia( string nTitle, string nFecha, string nReportero){
            title = nTitle;
            fecha = nFecha;
            reportero = nReportero;
        }

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
        //Metodo abstracto ToString()-getInfo()
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
        //Constructor
        //Llama al constructor de la clase madre y tambien asigna el atributo que no corresponde a la clase madre
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
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tLink para foto de noticia: " << linkFoto <<endl;
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
        //Constructor
        //Llama al constructor de la clase madre y tambien asigna el atributo que no corresponde a la clase madre
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
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tLink para Audio de noticia: " << linkAudio <<endl;
        }

};

//____________________________________________________________________________________________________________________________________
//Clase Noticia paper
//Hereda de clase noticia
//Atributos: Ruta a archivo para la foto y los que hereda de la clase madre
class TnoticiaDigital : public TNoticia {
    private:
        vector<TMedia> media;
    public:
        //Constructor
        //Llama al constructor de la clase madre y tambien asigna el atributo que no corresponde a la clase madre
        TnoticiaDigital(string nTitle, string nFecha, string nReportero, vector<TMedia> nMedia): TNoticia(nTitle,nFecha,nReportero){
            media = nMedia;
        }

        //SETTERS Y GETTERS
        void setLink(vector<TMedia> nMedia){
            media = nMedia;
        }

        vector<TMedia> getMedia(){
            return media;
        }

        //Metodo para agregar media a la noticia
        void agregarMedia(string url_media, tipoMedia type, string nInfoA){
            TMedia media1(url_media, type, nInfoA );
            media.push_back(media1);
        }

        //Metodo toString
        void getInfo(){
            cout << "Titulo: " << title << "\n\tFecha: " << fecha << "\n\tReportero: " << reportero << "\n\tMedia: \n";
            //Ciclo for para desplegar el contenido del vector en la lista de media
            for(int i = 0; i< media.size(); i++){
                media[i].toString();
            }
        }
};

//FUNCIONES-------------------------------------------------------------------------------------------------------------------------
//Funcion para agregar media a la noticia
//Entradas: Recibe un vector con media, un string con el url y un tipo 
//Salidas: Retorna el vector modificado
vector<TMedia> agregarMedia(vector<TMedia> media, string url_media, tipoMedia type, string nInfoA){
    TMedia media1(url_media, type, nInfoA );
    media.push_back(media1);
    return media;
}

//MAIN-------------------------------------------------------------------------------------------------------------------------------
int main(){
    //vector para media de noticias digitales
    vector<TMedia> mediaP;

    //Vector para almacenar los objetos 
    vector<TNoticia*> adminNoticias;

    //Instaciaciones y llamados a constructores----------------------------------------------------------------------------------------------------

    //Creacion del objeto de tipo Noticia Paper
    cout << "Creando objeto de tipo noticia paper..."<< endl;
    TnoticiaPaper noticia1("El caos en la vacunación multiplica las renuncias por miedo", \
    "10/04/2021", "El Mundo", "https://e00-elmundo.uecdn.es/assets/multimedia/imagenes/2021/04/09/16180028369004.png");

    //Creacion del objeto de tipo Noticia Radio
    cout << "Creando objeto de tipo noticia Radio..."<< endl;
    TnoticiaRadio noticia2("Fin de semana violento: 10 personas fueron asesinadas", "28/2/2022", "Dudly Lynch",\
     "https://www.teletica.com/sucesos/fin-de-semana-violento-10-personas-fueron-asesinadas_306340");

    //Creacion del objeto de tipo Noticia Digital
    cout << "Creando objeto de tipo noticia Digital..."<< endl;
    mediaP= agregarMedia(mediaP, "https://ichef.bbci.co.uk/news/800/cpsprodpb/128D3/production/_123478957_index_4_police_station_kharkiv_ukraine_getty.jpg.webp", foto, "From GETTY IMAGES ");
    mediaP= agregarMedia(mediaP, "https://ichef.bbci.co.uk/news/800/cpsprodpb/2D39/production/_123477511_ukraine_cities_mundo_2x640-nc.png.webp", foto, "Map");
    mediaP= agregarMedia(mediaP, "https://www.bbc.com/mundo/av-embeds/noticias-internacional-60578483", video, "Descripcion: Un misil golpeó un edificio de gobierno de Járkiv, la segunda ciudad de Ucrania. ");
    TnoticiaDigital noticia3("Rusia y Ucrania: Moscú lanza un asalto aéreo sobre Járkiv, estrecha el cerco sobre Kiev y reivindica el control de Jersón", \
    "01/03/2022", "BBC News Mundo", mediaP);

    adminNoticias={&noticia1,&noticia2};
    adminNoticias.push_back(&noticia3);
 

   cout<< "\nNoticias en la lista de noticias: "<< endl;
    for(int i=0; i < adminNoticias.size(); i++){
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<< endl;
        adminNoticias[i]->getInfo();
        cout<<"\n";
    } 

    return 0;
}