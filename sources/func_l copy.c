

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

char *change_date(char *str)
{
    char *modified = malloc(sizeof(char) * 13);
    int i = 4;
    int n = 0;

    while (i != 16) {
        modified[n] = str[i];
        i++;
        n++;
    }
    modified[n] = '\0';
    return (modified);
}

char *date(char *name, char *fullpath)
{
    int mtime;
    struct stat fileStat;
    stat(fullpath, &fileStat);
    return (change_date(ctime(&fileStat.st_atime)));
}

int total(char *name, char *fullpath)
{
    struct stat fileStat;
    stat(fullpath, &fileStat);  
    return (fileStat.st_blocks);
}

int link_counts(char *name, char *fullpath)
{
    struct stat fileStat;

    stat(fullpath, &fileStat);  
    return (fileStat.st_nlink);
}

char *user_name(char *name, char *fullpath)
{
    struct stat fileStat;
    struct passwd *pw = getpwuid(fileStat.st_uid);
    return (pw->pw_name);
}

char *goup_name(char *name, char *fullpath)
{
    struct stat fileStat;
    struct group  *gr = getgrgid(fileStat.st_gid);
    return (gr->gr_name);
}

int size(char *name, char *fullpath)
{
    struct stat fileStat;
    return (fileStat.st_size);
}

char *permisions(char *name, char *fullpath)
{
    char *temp = malloc(sizeof(char) * 11);
    struct stat fileStat;
    stat(fullpath, &fileStat);
    temp[0] = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
    temp[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    temp[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    temp[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    temp[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    temp[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    temp[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    temp[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    temp[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    temp[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    temp[10] = '\0';
    return temp;
}

void printlinked(t_info_files *file)
{
    t_info_files *tmp = file;
    tmp = tmp->next;

    printf("total %d\n", file->total);
    while (tmp != NULL)
    {
        printf("%s ",tmp->permisions);
        printf("%i ", tmp->linkcount);
        printf("%s ", tmp->owner);
        printf("%s ", tmp->group);
        printf("%i ", tmp->filesize);
        printf("%s ", tmp->date);
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
}

t_info_files *ini_new_info_files(char* name, char* filepath)
{
    t_info_files *file = malloc(sizeof(t_info_files));

    file->name = name;
    if (file == NULL)
        printf("error\n");

    file->name = strdup(name);
    file->permisions = permisions(name, filepath);
    file->date = date(name, filepath);
    file->filesize = size(name, filepath);
    file->linkcount = link_counts(name, filepath);
    file->group = goup_name(name, filepath);
    file->owner = user_name(name, filepath);
    file->next = NULL;
    return file;
}

void create_new(t_info_files *file, char *filepath, char *name)
{
    t_info_files *tmp = file;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_new_info_files(name, filepath);
}

char *func_fullpath(char *filepath, char *name, char *fullpath)
{
    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    return (fullpath);
}

void func_l(char *filepath)
{
    t_var *var = malloc(sizeof(t_var));
    t_info_files *first_file = NULL;
    t_info_files *added_file = NULL;
    struct dirent *dirp;
    char *fullpath;
    int number_of_nodes = 0;
    DIR *dp;
    first_file = (t_info_files *)malloc(sizeof(t_info_files));

    dp = opendir(filepath);
    errormanager_directories (filepath);
    while ((dirp = readdir(dp)) != NULL) {
        fullpath = malloc(strlen(filepath) + 2 + strlen(dirp->d_name));
        if (dirp->d_name[0] != '.' && dirp->d_name[1] != '.') {
            if (first_file = NULL){
                create_new(first_file, func_fullpath(filepath, dirp->d_name, fullpath), dirp->d_name);
                if (first_file != NULL)
                    added_file = first_file;
            }else {
                create_new(added_file->next, func_fullpath(filepath, dirp->d_name, fullpath), dirp->d_name);
               if (added_file->next != NULL)
                   added_file = added_file->next;
            }
        }
    }
    //sortLinkedList(number_of_nodes, first_file);
    free(fullpath);
    free(var);
    //printlinked(first_file);
    free(first_file);
    first_file = NULL;
    added_file = NULL;
    closedir(dp);
}


/*

void func_l(char *filepath)
{
    int i = 0;
    char *filepath = argv[1];
    //char *filepath = argv[1];
    t_var *var = malloc(sizeof(t_var));
    char *name;
    t_info_files *file = malloc(sizeof(t_info_files));
    //file->next = NULL;
    file->next = NULL;
    struct dirent *dirp;
    DIR *dp;
    int tmp = 0;
    dp = opendir(filepath);
    while ((dirp = readdir(dp)) != NULL) {
        name = dirp->d_name;
        if (name[0] != '.' && name[1] != '.') {
            //create_new(file, filepath, name, tmp);
            //tmp++;
            file = ini_new_info_files(name, filepath);
            printf("permisions: %s\n",file->permisions);
            printf("date: %i\n", file->date);
            printf("size: %i\n", file->filesize);
            printf("linkcounts: %i\n", file->linkcount);
            printf("group: %i\n", file->group);
            printf("size: %s\n", file->owner);
            file = file->next;
            create_new(file, filepath, name);
            tmp++;
        }
    }
    free(var);
    free(file);
    printlinked(file);
   //prints(file);
    free(file);
    closedir(dp);
    return (0);
}

*/































void func_d(char *filepath)
{
    t_var *var = malloc(sizeof(t_var));
    t_info_files *file = malloc(sizeof(t_info_files));
    file->next = NULL;
    int tmp = 0;

    create_new(file, filepath, filepath);

    free(var);
    printlinked(file);
    free(file);
}

void func_w(char *filepath)
{
    int i = 0;
    struct dirent *dirp;
    DIR *dp;
    

    dp = opendir(filepath);
    errormanager_directories (filepath);
    while ((dirp = readdir(dp)) != NULL) {
        if (dirp->d_name[0] != '.' && dirp->d_name[1] != '.') {
            printf("%s ", dirp->d_name);
        }
    }
    printf("\n");
    closedir(dp);
}