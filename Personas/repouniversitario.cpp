#include "repouniversitario.h"

RepoUniversitario::RepoUniversitario() : m_filename("universitarios.rep")
{

}

void RepoUniversitario::insertar_universitario(shared_ptr<Universitario> &universitario)
{
// universitarios.push_back(universitario);
}

bool RepoUniversitario::guardar_universitarios(shared_ptr<Universitario> &universitario)
{
    /*int id = generaId();
    universitario->setId(id);

    ofstream f( m_filename, ios::binary | ios::app);
    if ( !f ) // operador ! sobrecargado
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return false;
    } // fin de if

    else
    {
        f.seekp((id-1)*sizeof (Universitario));
        f.write(reinterpret_cast<char*>(&*universitario),sizeof (Universitario));

        f.close();
        return  true;
    }*/
}

list<shared_ptr<Universitario> > RepoUniversitario::leerUniversitarios()
{
   /* list<shared_ptr<Universitario>> list_Universitario;
    Universitario univ("",0,0,0,"");
    fstream f(m_filename, ios::binary | ios::out | ios::in);
    if(!f)
    {
        cerr << "No fichero";
    }
    else
    {
        int id = 0;
        while (!(f.eof())) {
            f.seekg((id++)*sizeof (Universitario));
            f.read(reinterpret_cast<char*>(&univ),sizeof (Universitario));
            if(univ.getId() != 0)
            {
                list_Universitario.push_back(make_shared<Universitario>(univ));
            }
            f.peek();
        }
    }
    f.close();
    return list_Universitario;*/
}

bool RepoUniversitario::eliminar(int id)
{
  /*  Universitario univ("",0,0,0.0,"");
    fstream f(m_filename, ios::binary | ios::out | ios ::in);
    if(!f)
    {
        cerr<< "No fichero";
        return false;
    }
    else
    {
        f.seekp((id-1)*sizeof (Universitario));
        f.write(reinterpret_cast<char*>(&univ),sizeof (Universitario));
    }
    f.close();
    return true;*/
}

int RepoUniversitario::generaId()
{
    int tam_f = tam_fichero()/sizeof (Universitario);
    tam_f ++;
    return tam_f;
}

int RepoUniversitario::tam_fichero()
{
    struct stat sb;
    if(stat(m_filename, &sb) == -1)
    {
        perror("stat");
    }
    return sb.st_size;
}
