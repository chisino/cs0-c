#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rss.h"

// implement these functions

Rss * createEmptyRss() {
  return createRss("", "", "", "");
}

Rss * createRss(const char * title, const char * link, const char * date, const char * description) {
  Rss *rss = (Rss *)malloc(sizeof(rss) * 1);

  rss->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(rss->title, title);

  rss->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(rss->link, link);

  rss->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(rss->description, description);

  strptime(date, "%m/%d/%Y", &(rss->dateStructure));

  return rss;
}


void printRss(Rss * item) {
  printf("%s\n, %s\n (%s\n, %4d-%02d-%02d)\n", item->title,
          item->link, item->description,
          (item->dateStructure.tm_year + 1900), (item->dateStructure.tm_mon + 1),
          item->dateStructure.tm_mday);

  return;
}
