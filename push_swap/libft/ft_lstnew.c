


t_list	*ft_lstnew(void *content)
{
	t_list	*last;

	last = (t_list*) malloc(sizeof(*last));
	if (!last)
		return (NULL);
	last->content = content;
	last->next  = NULL;
	return (last);
}
