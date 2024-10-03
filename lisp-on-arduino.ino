struct atom {
	void *data;
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

struct atom cdr(struct cons list) {
	return(list->cdr);
}
