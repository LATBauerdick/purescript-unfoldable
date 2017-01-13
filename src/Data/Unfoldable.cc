///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unfoldable.cc
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
#include "Unfoldable.hh"

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
  auto unfoldrArrayImpl( const any& isNothing,
                         const any& fromJust,
                         const any& fst,
                         const any& snd,
                         const any& f,
                         const any& b_ ) -> any::array {
    auto b = b_;
    any::array result;
    while (true) {
      const auto maybe = f(b);
      if (isNothing(maybe)) {
        return result;
      }
      const auto tuple = fromJust(maybe);
      result.push_back(fst(tuple));
      b = snd(tuple);
    }
  }

}
