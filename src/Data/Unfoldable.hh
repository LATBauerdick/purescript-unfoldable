///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unfoldable.hh
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Unfoldable FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_UnfoldableFFI_HH
#define Data_UnfoldableFFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Unfoldable {

  using namespace PureScript;

  // foreign import unfoldrArrayImpl
  //   :: forall a b
  //    . (forall x. Maybe x -> Boolean)
  //   -> (forall x. Maybe x -> x)
  //   -> (forall x y. Tuple x y -> x)
  //   -> (forall x y. Tuple x y -> y)
  //   -> (b -> Maybe (Tuple a b))
  //   -> b
  //   -> Array a
  //
  auto unfoldrArrayImpl( const any&,
                         const any&,
                         const any&,
                         const any&,
                         const any&,
                         const any& ) -> any::array;
}

#endif // Data_UnfoldableFFI_HH
