/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#ifndef TRINITY_TYPECONTAINERVISITOR_H
#define TRINITY_TYPECONTAINERVISITOR_H

/*
 * @class TypeContainerVisitor is implemented as a visitor pattern.  It is
 * a visitor to the ContainerMapList.  The visitor has to overload its types as
 * a visit method is called.
 */

#include "Define.h"
#include "Dynamic/TypeContainer.h"

namespace Trinity {

namespace Detail {

// terminate condition container map list
template <typename Visitor>
void VisitorHelper(Visitor &/*v*/, ContainerMapList<TypeNull> &/*c*/) { }

template <typename Visitor, typename T>
void VisitorHelper(Visitor &v, ContainerMapList<T> &c)
{
    v.Visit(c.elements);
}

// recursion container map list
template <typename Visitor, typename Head, typename Tail>
void VisitorHelper(Visitor &v, ContainerMapList<TypeList<Head, Tail>> &c)
{
    VisitorHelper(v, c.head);
    VisitorHelper(v, c.tail);
}

// for TypeMapContainer
template <typename Visitor, typename ObjectTypes>
void VisitorHelper(Visitor &v, TypeMapContainer<ObjectTypes> &c)
{
    VisitorHelper(v, c.objectMap());
}

} // namespace Detail

template <typename Visitor, typename TypeContainer>
class TypeContainerVisitor final
{
public:
    TypeContainerVisitor(Visitor &v)
        : i_visitor(v)
    { }

    void Visit(TypeContainer &c)
    {
        Trinity::Detail::VisitorHelper(i_visitor, c);
    }

private:
    Visitor &i_visitor;
};

} // namespace Trinity

#endif
