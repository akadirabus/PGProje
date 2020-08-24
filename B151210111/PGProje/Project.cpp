/****************************************************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
** B�LG�SAYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R��� DERS�
**
** �DEV NUMARASI.............: I
** ��RENC� ADI...............: ABDULKAD�R ABU�
** ��RENC� NUMARASI..........: B151210111
** DERS GRUBU................: 1A
****************************************************************************/

//Proje ��lemleri Main Class
#include "Project.h"
#include <fstream>
#include <locale.h>


void Project::writeProjectFile(Project& project, string fileName)//Dosyay Yaz
{
    ofstream file;

    file.open(fileName, ios::app);

    file << project.getProjectId() << ". " << project.getProjectName() << "-" << project.getProjectManager() << "-" << project.getProjectController() << "-" << project.getProjectCompanyName() << "\n";

    file.close();
}

int Project::getProjectCount(string fileName)//Proje Say�s�n� Getir
{
    ifstream file;

    file.open(fileName);
    file >> noskipws;

    string line;

    int lineCount = 0;

    while (getline(file, line))
    {
        lineCount++;
    }

    return lineCount;
}

void Project::removeProject(const char* file_name, int n) //Proje Sil
{
    ifstream fin(file_name);
    ofstream fout;
    fout.open("temp.txt", ios::out);

    char ch;
    int line = 1;
    while (fin.get(ch))
    {
        if (ch == '\n')
            line++;

        if (line != n)      
            fout << ch;
    }
    fout.close();
    fin.close();
    remove(file_name);
    rename("temp.txt", file_name);
}

