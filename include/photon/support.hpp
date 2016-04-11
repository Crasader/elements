/*=================================================================================================   Copyright (c) 2016 Joel de Guzman   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.   http://creativecommons.org/licenses/by-sa/4.0/=================================================================================================*/#if !defined(PHOTON_GUI_LIB_SUPPORT_APRIL_10_2016)#define PHOTON_GUI_LIB_SUPPORT_APRIL_10_2016#include <photon/point.hpp>#include <photon/rect.hpp>#include <cfloat>namespace photon{	////////////////////////////////////////////////////////////////////////////////////////////////	// Limits	////////////////////////////////////////////////////////////////////////////////////////////////   struct size_limits   {      point min;      point max;   };   constexpr double        max_double = DBL_MAX;   constexpr size_limits   full_limits =  { { 0.0, 0.0 }, { max_double, max_double } };   constexpr size_limits   empty_limits = { { 0.0, 0.0 }, { 0.0, 0.0 } };   constexpr rect          empty_rect =   { 0.0, 0.0, 0.0, 0.0 };	////////////////////////////////////////////////////////////////////////////////////////////////	// Layout	////////////////////////////////////////////////////////////////////////////////////////////////   class window;   class app;   struct layout_info   {      app&           app;      window&        window;      layout_info*   parent;      rect&          bounds;   };	////////////////////////////////////////////////////////////////////////////////////////////////	// key info	////////////////////////////////////////////////////////////////////////////////////////////////   struct key_info   {      int   key;      int   scancode;      int   action;      int   modifiers;   };	////////////////////////////////////////////////////////////////////////////////////////////////	// Utilities	////////////////////////////////////////////////////////////////////////////////////////////////   template <typename T, typename U>   inline void max_limit(T& val, U const& max)   {      if (val > max)         val = max;   }   template <typename T, typename U>   inline void min_limit(T& val, U const& min)   {      if (val < min)         val = min;   }   template <typename T, typename U, typename V>   inline void limit(T& val, U const& min, V const& max)   {      min_limit(val, min);      max_limit(val, max);   }   template <typename T, typename U, typename V>   inline bool within(T const& val, U const& min, V const& max)   {      return (val >= min) && (val <= max);   }}#endif