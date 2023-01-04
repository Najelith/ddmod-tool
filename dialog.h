#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QMatrix4x4>
#include <vector>
#include <map>
#include "renderer/mainwidget.h"

//remove me later
#include <QDebug>

/*
namespace Ui {
class Dialog;
}
*/
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QByteArray Readbyte(char* buffer, int &offset);
    QByteArray Readlong(char* buffer, int &offset);
    QByteArray ReadBElong(char* buffer, int &offset);
    QByteArray Readshort(char* buffer, int &offset);
    QByteArray ReadBEshort(char* buffer, int &offset);
    QByteArray ReadBEpointer(char* buffer, int &offset, bool x64);
    QByteArray Readpointer(char* buffer, int &offset, bool x64);
    QByteArray ReadBEfloat (char* buffer, int &offset, bool x64);
    QByteArray Readfloat(char* buffer, int &offset, bool x64);
    void ReadMatrix44(char* buffer, int &offset,std::vector<QByteArray> &dest);
    void ReadBEMatrix44(char* buffer, int &offset,std::vector<QByteArray> &dest);
    QByteArray ReadMaterial(char* buffer, int &offset);
    void WriteMaterial(FILE *f, QByteArray & bytes);
    void WriteMatrix44(FILE *f,int offset, std::vector<QByteArray> &dest);
    void WriteBEMatrix44(FILE *f,int offset, std::vector<QByteArray> &dest);
    void Writebyte(FILE *f, QByteArray & bytes);
    void Writelong(FILE *f, QByteArray & bytes);
    void WriteBElong(FILE *f,QByteArray & bytes);
    void Writeshort(FILE *f, QByteArray & bytes);
    void WriteBEshort(FILE *f, QByteArray & bytes);





private slots:
    void on_btnListen_clicked();
    void on_addr_changed(QString fileName);
    void on_btnClose_clicked();


private:
  //  Ui::Dialog *ui;
     long int goffset ; // global write offset
    std::map<QByteArray,long int> blocktype;
    std::map<QByteArray,long int> unknownblocktypes;
    std::map<QByteArray,long int> unknownbyte3;
    std::map<QByteArray,QByteArray> byte3map;
    int unktypesfound;
    int unkbyte3found;

 std::vector< std::vector<QByteArray> > faces;

    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
        QVBoxLayout *outerLayout;
            QVBoxLayout *insideboxLayout;

    QRadioButton *rdoSingle;
    QRadioButton *rdoPooled;
    QRadioButton *rdoTheaded;
    QLabel *label_2;
    QLineEdit *spinBoxMax;
    QLineEdit *spinBox;
    QLabel *label;
    QLabel *label_3;
    QLabel *difflabel;
    QLabel *speclabel;
    QLabel *normlabel;
    QLabel *litelabel;

    QComboBox *cmbAddress;
    QLineEdit *spinboxIdle;


    QLabel *label_meshcount;
    QLineEdit *meshcount;
    QLabel *label_materialcount;
    QLineEdit *materialcount;
    QLabel *label_vertexcount;
    QLineEdit *vertexcount;



    QLabel *label_facecount;
    QLineEdit *facecount;
    QLabel *label_vertexids;
    QLineEdit *vertexids;
    QLabel *label_vertexbuffersize;
    QLineEdit *vertexbuffersize;


    QLabel *label_scondbuffersize;
    QLineEdit *scondbuffersize;
    QLabel *label_groupcount;
    QLineEdit *groupcount;
    QLabel *label_bonesoffset;
    QLineEdit *bonesoffset;


    QLabel *label_groupoffset;
    QLineEdit *groupoffset;
    QLabel *label_textureoffset;
    QLineEdit *textureoffset;
    QLabel *label_meshoffset;
    QLineEdit *meshoffset;




    QLabel *label_vertexoffset;
    QLineEdit *vertexoffset;
    QLabel *label_facesoffset;
    QLineEdit *facesoffset;
    QLabel *label_unkoffset;
    QLineEdit *unkoffset;

    QLabel *label_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_0;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnListen;
    QPushButton *btnClose;
    //3d renderer for later
    struct MODHeader
    {
        QByteArray id;
        QByteArray version2; //byte
        QByteArray version;
        bool BEndian;
        QByteArray bonecount; //short
        QByteArray meshcount;
        QByteArray materialcount;
        QByteArray vertexcount;
        QByteArray facecount;
        QByteArray vertexids;
        QByteArray vertexbuffersize;
        QByteArray scondbuffersize;
        QByteArray texturecount;
        QByteArray groupcount; //x64 pointer
        QByteArray bonemapcount; //x64 pointer
        QByteArray bonesoffset; //x64 pointer
        QByteArray groupoffset; //x64 pointer
        QByteArray textureoffset; //x64 pointer
        QByteArray meshoffset; //x64 pointer
        QByteArray vertexoffset; //x64 pointer
        QByteArray vertex2offset;
        QByteArray facesoffset; //x64 pointer
        QByteArray unkoffset; //x64 pointer
        QByteArray unkoffset2;
        // bbsphereposition vec3
        QByteArray bbsphereradius;
        // bbmin vec3 long
        // bbmax vec3 long
    } Mheader;

    struct MOD_unk1_header
    {
        QByteArray un1;
        QByteArray un2;
        QByteArray un3;
        QByteArray un4;
        QByteArray un5;
        QByteArray un6;
        QByteArray un7;
        QByteArray un8;
        QByteArray un9;
        QByteArray un10;
        QByteArray un11;
        QByteArray un12;
        QByteArray un13;
        QByteArray un14;
        QByteArray un15;
        QByteArray un16;  // on pc dd;da it is "0000CDCD" on ps3 it's all 0's
        QByteArray un17;

    } Mhunk1;

    struct MOD_Bone_info
    {
        QByteArray id;
        QByteArray parentid;
        QByteArray child;
        QByteArray unk;
        QByteArray lmatref;
        QByteArray amatref;

        QByteArray unk1;

        QByteArray unk2;

        QByteArray unk3;

        QByteArray unk4;

        QByteArray unk5;

    };

    struct MOD_bones
    {


        std::vector<MOD_Bone_info> boneinfo;
        std::vector<QByteArray> lmatrices;
        std::vector<QByteArray> amatrices;
        int remaptablesize;
        std::vector<QByteArray> remaptable;

        QMatrix4x4 mtx; //unused till rendering

    } Mbones;

    struct MOD_Group_info
    {
        //header
        QByteArray h0; //ddon pc has the only value
        QByteArray h1; // dd;da pc has cdcdcdcd ps3 has 000000
        QByteArray h2;
        QByteArray h3;
        //body?
        QByteArray b0;
        QByteArray b1;
        QByteArray b2;
        QByteArray b3;


    };

    struct MOD_Groups
    {
        std::vector<MOD_Group_info> groupinfo;
    } Mgroups;

    struct MOD_Materials
    {
        std::vector<QByteArray> name;
    } Mmats;

    struct MOD_Mesh_Data
    {
        std::vector<QByteArray> verticies;
        std::vector<QByteArray> texturemap;
        std::vector<QByteArray> normals;
        std::vector<QByteArray> weights;
        std::vector< std::vector<QByteArray> > faces; //array of triangle strips as qbytearray per int val
        std::vector<QByteArray> bns;
        std::vector<QByteArray> unkbyte1;
        std::vector<QByteArray> unklong2;
        std::vector<QByteArray> unksh1;
        std::vector<QByteArray> unksh2;
        std::vector<QByteArray> unksh3;
        std::vector<QByteArray> unksh4;

        std::vector<QByteArray> unklong1;
        std::vector<QByteArray> unklong3;

        std::vector<QByteArray> unklong4;
        std::vector<QByteArray> unklong5;


    };

    struct MOD_Mesh_Part2
    {
        QByteArray unksh1;
        QByteArray vertexcount;
        QByteArray id;
        QByteArray material;
        QByteArray LOD;
        QByteArray unkbyte20;
        QByteArray unkbyte21;
        QByteArray blocksize;
        QByteArray unkbtye3;
        QByteArray vertexsub;
        QByteArray vertexoffset;
        QByteArray blocktype;
        QByteArray faceoffset;
        QByteArray facecount;
        QByteArray unklong4;
        QByteArray unkbyte5;
        QByteArray boneremapid;
        QByteArray unksh6;
        QByteArray unksh7;
        QByteArray unksh8;
        QByteArray unklong; /// pc E0,00,??,1D   ps3.... gibberish?
        std::vector<MOD_Mesh_Data> meshdata; // why is this a vector? it only ever does this once
    };
    struct MOD_unk2_chunk
    {
        QByteArray un1;
        QByteArray un2; // on pc dd;da it is "CDCDCDCD" on ps3 it's all 0's
        QByteArray un3; // on pc dd;da it is "CDCDCDCD" on ps3 it's all 0's
        QByteArray un4; // on pc dd;da it is "CDCDCDCD" on ps3 it's all 0's
        QByteArray un5;
        QByteArray un6;
        QByteArray un7; //body begin
        QByteArray un8;
        QByteArray un9;
        QByteArray un10;
        QByteArray un11;
        QByteArray un12;
        QByteArray un13;
        QByteArray un14;
        QByteArray un15;
        QByteArray un16;
        QByteArray un17;
        QByteArray un18;
        QByteArray un19;
        QByteArray un20;
        QByteArray un21;
        QByteArray un22;
        QByteArray un23;
        QByteArray un24;
        QByteArray un25;
        QByteArray un26;
        QByteArray un27;
        QByteArray un28;
        QByteArray un29;
        QByteArray un30;
        QByteArray un31;
        QByteArray un32;
        QByteArray un33;
        QByteArray un34;
        QByteArray un35;
        QByteArray un36;

    } ;

    struct MOD_Mesh_Parts
    {
//        QByteArray mtxcount;
//        std::vector<QByteArray> matrices;
        std::vector<MOD_Mesh_Part2> parts;
        std::vector<MOD_unk2_chunk> chunks;
    } Mparts;



    void open_file(QString fileName);

signals:

    void newTextures(QString fileName);
    void newMesh(MOD_Mesh_Parts &mesh, std::vector<QByteArray> &lmatrices, std::vector<QByteArray> &amatrices);
    void newDAPCMesh(MOD_Mesh_Parts &mesh);
};

#endif // DIALOG_H
