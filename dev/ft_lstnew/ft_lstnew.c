
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    void    *content;
    struct  s_list *next;
}   t_list;




t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}