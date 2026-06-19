p = rearA->next;
rearA->next = rearB->next->next;
q = rearB->next;
rearB->next = p;
free(q);
