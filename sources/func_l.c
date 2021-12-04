

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
    return (change_date(ctime(&fileStat.st_mtime)));
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

void printlinked_d(t_info_files *file)
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
    printf("\n");
}

void printlinked(t_info_files *file)
{
    t_info_files *tmp = file;
    int total = 0;
    tmp = tmp->next;
    while (tmp != NULL) {
        total += (tmp->total);
        tmp = tmp->next;
    }
    tmp = file;
    tmp = tmp->next;
    printf("total %d\n", total / 2);
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
    printf("\n");
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
    file->total = total(name, filepath);
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
    t_info_files *file = malloc(sizeof(t_info_files));
    file->next = NULL;
    struct dirent *dirp;
    char *fullpath;
    int numberOfNodes = 0;
    DIR *dp;

    dp = opendir(filepath);
    errormanager_directories (filepath);
    while ((dirp = readdir(dp)) != NULL) {
        fullpath = malloc(strlen(filepath) + 2 + strlen(dirp->d_name));
        if (dirp->d_name[0] != '.' && dirp->d_name[1] != '.') {
            create_new(file, func_fullpath(filepath, dirp->d_name, fullpath), dirp->d_name);
            numberOfNodes++;
        }
    }
    free(fullpath);
    free(var);
    printlinked(file);
    free(file);
    closedir(dp);
}

void func_ld(char *filepath)
{
    t_var *var = malloc(sizeof(t_var));
    t_info_files *file = malloc(sizeof(t_info_files));
    file->next = NULL;
    int tmp = 0;

    create_new(file, filepath, filepath);
    free(var);
    printlinked_d(file);
    free(file);
}

void func_d(char *filepath)
{
    printf("%s\n", filepath);
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