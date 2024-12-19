/***********************************************************************
 * Header:
 *    Array
 * Summary:
 *    Our custom implementation of std::array
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *       array             : similar to std::array
 *       array :: iterator : an iterator through the array
 * Author
 *    Nathan Bird
 ************************************************************************/

#pragma once

#include <stdexcept>

class TestArray; // forward declaration for unit tests

namespace custom
{

   /************************************************
    * ARRAY
    * A class that holds stuff
    ***********************************************/
   template <typename T, int N>
   struct array
   {
   public:
      //
      // Construct
      //

      // No constructors or destructors needed here

      //
      // Assign
      //

      // No assignment operators needed here

      //
      // Iterator
      //

      // Forward declaration for the iterator class
      class iterator;

      // Begin and end methods
      iterator begin()
      {
         /* your code goes here; it should return an iterator referring to the first element in the array */
         return iterator();
      }
      iterator end()
      {
         /* your code goes here; it should return an iterator referring to the first element off the end of the array */
         return iterator();
      }

      // 
      // Access
      //

      // Subscript
      T& operator [] (size_t index)
      {
         return __elems_[index];
      }
      const T& operator [] (size_t index) const
      {
         return __elems_[index];
      }

      // At
      T& at(size_t index)
      {
         if (index >= size())
         {
            throw std::out_of_range("ARRAY: index out of range");
         }
         return __elems_[index];
      }
      const T& at(size_t index) const
      {
         if (index >= size())
         {
            throw std::out_of_range("ARRAY: index out of range");
         }
         return __elems_[index];
      }

      // Front and Back
      T& front()
      {
         return at(0);
      }
      T& back()
      {
         return at(size() - 1);
      }
      const T& front() const
      {
         return at(0);
      }
      const T& back()  const
      {
         return at(size() - 1);
      }

      //
      // Remove

      // No clear or erase here

      //
      // Status
      //

      // number of elements in the array
      size_t size()  const
      {
         return N;
      }
      bool empty() const
      {
         return !N;
      }

      //
      // Member Variable
      //

      // statically allocated array of T
      T __elems_[N];
   };



   /**************************************************
    * ARRAY ITERATOR
    * An iterator through array
    *************************************************/
   template <typename T, int N>
   class array <T, N> ::iterator
   {
      friend class ::TestArray; // give unit tests access to the privates
   public:
      // constructors, destructors, and assignment operator
      iterator()
      {
         /* your code goes here; it should initialize an iterator */
      }
      iterator(T* p)
      {
         /* your code goes here; it should point to an element in the array */
      }
      iterator(const iterator& rhs)
      {
         /* your code goes here; it should copy an iterator */
      }
      iterator& operator = (const iterator& rhs)
      {
         /* your code goes here; it should copy an iterator */
         return *this;
      }

      // equals, not equals operator
      bool operator != (const iterator& rhs) const
      {
         /* your code goes here; it should not always return TRUE */
         return true;
      }
      bool operator == (const iterator& rhs) const
      {
         /* your code goes here; it should not always return TRUE */
         return true;
      }

      // dereference operator
      T& operator * ()
      {
         /* your code goes here; it should fetch the element referred to by p */
         return *(new T);
      }
      const T& operator * () const
      {
         /* your code goes here; it should fetch the element referred to by p */
         return T();
      }

      // prefix increment
      iterator& operator ++ ()
      {
         /* your code goes here; it should advance the iterator by one */
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         /* your code goes here; it should advance the iterator by one */
         return *this;
      }

   private:
      T* p;
   };



}; // namespace custom
