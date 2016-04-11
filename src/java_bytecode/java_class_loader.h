/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#ifndef CPROVER_JAVA_CLASS_LOADER_H
#define CPROVER_JAVA_CLASS_LOADER_H

#include <map>

#include <util/message.h>

#include "java_bytecode_parse_tree.h"

class java_class_loadert:public messaget
{
public:
  java_bytecode_parse_treet &operator()(const irep_idt &);
  
  // maps class names to the parse trees
  typedef std::map<irep_idt, java_bytecode_parse_treet> class_mapt;
  class_mapt class_map;

  static std::string file_to_class_name(const std::string &);
  static std::string class_name_to_file(const irep_idt &);
  
  inline void add_jar_file(const std::string &f)
  {
    jar_files.push_back(f);
  }

protected:
  struct jar_entryt
  {
    std::size_t index;
  };

  // maps jar files to maps of class names
  typedef std::map<irep_idt, std::map<irep_idt, jar_entryt> > jar_mapt;
  jar_mapt jar_map;
  
  void read_jar_file(const irep_idt &);

  // get a parse tree for given class
  java_bytecode_parse_treet &get_parse_tree(const irep_idt &);
  
  std::list<std::string> jar_files;
};

#endif
