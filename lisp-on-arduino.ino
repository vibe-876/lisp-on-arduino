struct atom {
	int *data;
}

int atom_init(struct atom *atom) {
	atom = malloc(sizeof(struct atom));
}

int atom_write(int data, struct atom *atom) {
	atom->data = malloc(sizeof(int));
	atom->*data = data;

	return(0);
}

int atom_read(struct atom *atom) {
	if(atom == NULL) return(-1);
	
	Serial.println(atom->data);
	return(0);
}

int atom_gc(struct atom *atom) {
	if(atom == 0x0) return(-1);
	free(atom);
	return(0);
}

struct cons {
	struct atom *car;
	struct cons *cdr;
};

struct atom car(struct cons list) {
	return(list->car);
}

struct cons cdr(struct cons list) {
	return(list->cdr);
}

struct cons append(struct cons *list, int data) {
	struct cons *pointer = list;
	if(pointer == 0x0) {
		pointer = malloc(sizeof(struct cons));
		pointer->cdr = 0x0;
	}

	while(pointer->cdr != 0x0) pointer = list->next;
	pointer->car = data;

	return(list);
}

int atom_equal(struct atom *atom_one, struct atom *atom_two) {
	if(atom_one->data == atom_two->data) return(0);
	return(-1);
}

int list_equal(struct cons *list_one, struct cons *list_two) {
	struct cons cdr_left = list_one;
	struct cons cdr_right = list_two
	while(cdr_left->next != 0x0 && cdr_right->next != 0x0) {
		if(cdr_left->car->data != cdr_right->car->data) return(-1);

		cdr_left = cdr_left->cdr;
		cdr_right = cdr_right->cdr;
	}
}
