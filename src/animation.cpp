#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"



void load_Animation(const char* fp) 
{
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(fp, 0);

    
}
