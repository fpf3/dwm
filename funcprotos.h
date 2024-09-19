#ifndef FUNCPROTOS_H
#define FUNCPROTOS_H

#include "types.h"
/* function declarations */
void applyrules(Client *c);
int applysizehints(Client *c, int *x, int *y, int *w, int *h, int interact);
void arrange(Monitor *m);
void arrangemon(Monitor *m);
void attach(Client *c);
void attachstack(Client *c);
void bigtile(Monitor *m);
void bumpfontsize(const Arg* arg);
void buttonpress(XEvent *e);
void checkotherwm(void);
void cleanup(void);
void cleanupmon(Monitor *mon);
void clientmessage(XEvent *e);
void configure(Client *c);
void configurenotify(XEvent *e);
void configurerequest(XEvent *e);
Monitor *createmon(void);
void destroynotify(XEvent *e);
void detach(Client *c);
void detachstack(Client *c);
Monitor *dirtomon(int dir);
void drawbar(Monitor *m);
void drawbars(void);
void enqueue(Client *c);
void enqueuestack(Client *c);
void enternotify(XEvent *e);
void expose(XEvent *e);
void focus(Client *c);
void focusin(XEvent *e);
void focusmon(const Arg *arg);
void focusstack(const Arg *arg);
char** fontset_gen(void);
void fontset_free(char** fontset);
Atom getatomprop(Client *c, Atom prop);
pid_t getparentprocess(pid_t p);
int getrootptr(int *x, int *y);
long getstate(Window w);
unsigned int getsystraywidth(void);
int gettextprop(Window w, Atom atom, char *text, unsigned int size);
void globalview(const Arg* arg);
void grabbuttons(Client *c, int focused);
void grabkeys(void);
void incnmaster(const Arg *arg);
int isdescprocess(pid_t p, pid_t c);
void keypress(XEvent *e);
void keyrelease(XEvent *e);
void killclient(const Arg *arg);
void launcher(void);
void load_xresources(void);
void manage(Window w, XWindowAttributes *wa);
void mappingnotify(XEvent *e);
void maprequest(XEvent *e);
void monocle(Monitor *m);
void motionnotify(XEvent *e);
void movemouse(const Arg *arg);
Client *nexttiled(Client *c);
void pomostart(void);
void pop(Client *);
void propertynotify(XEvent *e);
void quit(const Arg *arg);
void quitprompt(const Arg *arg);
Monitor *recttomon(int x, int y, int w, int h);
void reload(const Arg *arg);
void removesystrayicon(Client *i);
void resize(Client *c, int x, int y, int w, int h, int interact);
void resizebarwin(Monitor *m);
void resizeclient(Client *c, int x, int y, int w, int h);
void resizemouse(const Arg *arg);
void resizerequest(XEvent *e);
void resource_load(XrmDatabase db, char *name, enum resource_type rtype, void *dst);
void restack(Monitor *m);
void restore_session(void);
void rotatestack(const Arg *arg);
void run(void);
void runAutoStart(void);
void save_session(void);
void scan(void);
void scrolltag(const Arg* arg);
int sendevent(Window w, Atom proto, int m, long d0, long d1, long d2, long d3, long d4);
void sendmon(Client *c, Monitor *m);
void setclientstate(Client *c, long state);
void setfocus(Client *c);
void setfullscreen(Client *c, int fullscreen);
void sighup_handle(int unused);
void sigterm_handle(int unused);
void swallow(Client* c, Client* p);
Client* swallowingclient(Window w);
void fullscreen(const Arg *arg);
void togglepomo(void);
void setlayout(const Arg *arg);
void setmfact(const Arg *arg);
void setup(void);
void seturgent(Client *c, int urg);
void showhide(Client *c);
void sigchld(int unused);
void spawn(const Arg *arg);
Monitor *systraytomon(Monitor *m);
void tag(const Arg *arg);
void tagmon(const Arg *arg);
Client* termforwin(const Client *c);
void tile(Monitor *);
void togglealttag(const Arg *);
void togglebar(const Arg *arg);
void togglefloating(const Arg *arg);
void togglescratch(const Arg *arg);
void toggletag(const Arg *arg);
void toggleview(const Arg *arg);
void unfocus(Client *c, int setfocus);
void unmanage(Client *c, int destroyed);
void unmapnotify(XEvent *e);
void unswallow(Client* c);
void updatebarpos(Monitor *m);
void updatebars(void);
void updateclientlist(void);
int updategeom(void);
void updatenumlockmask(void);
void updatesizehints(Client *c);
void updatestatus(void);
void updatesystray(void);
void updatesystrayicongeom(Client *i, int w, int h);
void updatesystrayiconstate(Client *i, XPropertyEvent *ev);
void updatetitle(Client *c);
void updatewindowtype(Client *c);
void updatewmhints(Client *c);
void view(const Arg *arg);
pid_t winpid(Window w);
Client *wintoclient(Window w);
Monitor *wintomon(Window w);
Client *wintosystrayicon(Window w);
int xerror(Display *dpy, XErrorEvent *ee);
int xerrordummy(Display *dpy, XErrorEvent *ee);
int xerrorstart(Display *dpy, XErrorEvent *ee);
void zoom(const Arg *arg);
void zoomnext(const Arg *arg);

#endif /* FUNCPROTOS_H*/
