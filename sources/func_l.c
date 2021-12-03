

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

char *date(char *name, char *filepath)
{
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));
    int mtime;
    struct stat fileStat;

    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    stat(fullpath, &fileStat);
    free(fullpath);
    return (change_date(ctime(&fileStat.st_atime)));
}

int link_counts(char *name, char *filepath)
{
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));
    struct stat fileStat;

    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    stat(fullpath, &fileStat);  
    free(fullpath);
    return (fileStat.st_nlink);
}

char *user_name(char *name, char *filepath)
{
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));
    struct stat fileStat;
    
    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    struct passwd *pw = getpwuid(fileStat.st_uid);
    free(fullpath);
    return (pw->pw_name);
}

char *goup_name(char *name, char *filepath)
{
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));
    struct stat fileStat;

    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    struct group  *gr = getgrgid(fileStat.st_gid);
    free(fullpath);
    return (gr->gr_name);
}

int size(char *name, char *filepath)
{
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));
    struct stat fileStat;

    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
    free(fullpath);
    return (fileStat.st_size);
}

char *permisions(char *name, char *filepath)
{
    char *temp = malloc(sizeof(char) * 11);
    struct stat fileStat;
    char *fullpath = malloc(strlen(filepath) + 2 + strlen(name));

    strcpy(fullpath, filepath);
    if (filepath[strlen(filepath) - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, name);
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
    free(fullpath);
    return temp;
}

void printlinked(t_info_files *file)
{
    t_info_files *tmp = file;
    tmp = tmp->next;

    while (tmp != NULL) {
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

void func_l(char *filepath)
{
    int i = 0;
    //char *filepath = argv[1];
    t_var *var = malloc(sizeof(t_var));
    char *name;
    t_info_files *file = malloc(sizeof(t_info_files));
    file->next = NULL;
    struct dirent *dirp;
    DIR *dp;
    int tmp = 0;

    dp = opendir(filepath);
    while ((dirp = readdir(dp)) != NULL) {
        name = dirp->d_name;
        if (name[0] != '.' && name[1] != '.') {
            create_new(file, filepath, name);
            tmp++;
        }
    }
    free(var);
    printlinked(file);
    free(file);
    closedir(dp);
}
