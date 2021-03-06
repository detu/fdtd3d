#include "Grid.h"

template <>
GridCoordinate1D
Grid<GridCoordinate1D>::getChunkStartPosition () const
{
  return GRID_COORDINATE_1D (0, getSize ().getType1 ());
}

template <>
GridCoordinate2D
Grid<GridCoordinate2D>::getChunkStartPosition () const
{
  return GRID_COORDINATE_2D (0, 0, getSize ().getType1 (), getSize ().getType2 ());
}

template <>
GridCoordinate3D
Grid<GridCoordinate3D>::getChunkStartPosition () const
{
  return GRID_COORDINATE_3D (0, 0, 0, getSize ().getType1 (), getSize ().getType2 (), getSize ().getType3 ());
}

/**
 * Get first coordinate from which to perform computations at current step
 *
 * @return first coordinate from which to perform computations at current step
 */
template <>
GridCoordinate1D
Grid<GridCoordinate1D>::getComputationStart (const GridCoordinate1D & diffPosStart) const /**< offset from the left border */
{
  return GRID_COORDINATE_1D (0, getSize ().getType1 ()) + diffPosStart;
} /* Grid<GridCoordinate1D>::getComputationStart */

#if defined (MODE_DIM2) || defined (MODE_DIM3)

/**
 * Get first coordinate from which to perform computations at current step
 *
 * @return first coordinate from which to perform computations at current step
 */
template <>
GridCoordinate2D
Grid<GridCoordinate2D>::getComputationStart (const GridCoordinate2D & diffPosStart) const /**< offset from the left border */
{
  return GRID_COORDINATE_2D (0, 0, getSize ().getType1 (), getSize ().getType2 ()) + diffPosStart;
} /* Grid<GridCoordinate2D>::getComputationStart */

#endif /* MODE_DIM2 || MODE_DIM3 */

#if defined (MODE_DIM3)

/**
 * Get first coordinate from which to perform computations at current step
 *
 * @return first coordinate from which to perform computations at current step
 */
template <>
GridCoordinate3D
Grid<GridCoordinate3D>::getComputationStart (const GridCoordinate3D & diffPosStart) const /**< offset from the left border */
{
  return GRID_COORDINATE_3D (0, 0, 0, getSize ().getType1 (), getSize ().getType2 (), getSize ().getType3 ()) + diffPosStart;
} /* Grid<GridCoordinate3D>::getComputationStart */

#endif /* MODE_DIM3 */

/**
 * Check whether position is appropriate to get/set value from
 *
 * @return flag whether position is appropriate to get/set value from
 */
template<>
bool
Grid<GridCoordinate1D>::isLegitIndex (const GridCoordinate1D &position, /**< coordinate in grid */
                                      const GridCoordinate1D &sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();
  const grid_coord& sx = sizeCoord.get1 ();

  if (px >= sx)
  {
    return false;
  }

  return true;
} /* Grid<GridCoordinate1D>::isLegitIndex */

/**
 * Calculate one-dimensional coordinate from one-dimensional position
 *
 * @return one-dimensional coordinate from one-dimensional position
 */
template<>
grid_coord
Grid<GridCoordinate1D>::calculateIndexFromPosition (const GridCoordinate1D &position, /**< coordinate in grid */
                                                    const GridCoordinate1D &sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();

  return px;
} /* Grid<GridCoordinate1D>::calculateIndexFromPosition */

#if defined (MODE_DIM2) || defined (MODE_DIM3)

/**
 * Check whether position is appropriate to get/set value from
 *
 * @return flag whether position is appropriate to get/set value from
 */
template<>
bool
Grid<GridCoordinate2D>::isLegitIndex (const GridCoordinate2D &position, /**< coordinate in grid */
                                      const GridCoordinate2D &sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();
  const grid_coord& sx = sizeCoord.get1 ();

  const grid_coord& py = position.get2 ();
  const grid_coord& sy = sizeCoord.get2 ();

  if (px >= sx)
  {
    return false;
  }
  else if (py >= sy)
  {
    return false;
  }

  return true;
} /* Grid<GridCoordinate2D>::isLegitIndex */

/**
 * Calculate one-dimensional coordinate from two-dimensional position
 *
 * @return one-dimensional coordinate from two-dimensional position
 */
template<>
grid_coord
Grid<GridCoordinate2D>::calculateIndexFromPosition (const GridCoordinate2D &position, /**< coordinate in grid */
                                                    const GridCoordinate2D &sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();

  const grid_coord& py = position.get2 ();
  const grid_coord& sy = sizeCoord.get2 ();

  return px * sy + py;
} /* Grid<GridCoordinate2D>::calculateIndexFromPosition */

#endif /* MODE_DIM2 || MODE_DIM3 */

#if defined (MODE_DIM3)

/**
 * Check whether position is appropriate to get/set value from
 *
 * @return flag whether position is appropriate to get/set value from
 */
template<>
bool
Grid<GridCoordinate3D>::isLegitIndex (const GridCoordinate3D &position, /**< coordinate in grid */
                                      const GridCoordinate3D &sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();
  const grid_coord& sx = sizeCoord.get1 ();

  const grid_coord& py = position.get2 ();
  const grid_coord& sy = sizeCoord.get2 ();

  const grid_coord& pz = position.get3 ();
  const grid_coord& sz = sizeCoord.get3 ();

  if (px >= sx)
  {
    return false;
  }
  else if (py >= sy)
  {
    return false;
  }
  else if (pz >= sz)
  {
    return false;
  }

  return true;
} /* Grid<GridCoordinate3D>::isLegitIndex */

/**
 * Calculate one-dimensional coordinate from two-dimensional position
 *
 * @return one-dimensional coordinate from two-dimensional position
 */
template<>
grid_coord
Grid<GridCoordinate3D>::calculateIndexFromPosition (const GridCoordinate3D& position, /**< coordinate in grid */
                                                    const GridCoordinate3D& sizeCoord) /**< size of grid */
{
  const grid_coord& px = position.get1 ();

  const grid_coord& py = position.get2 ();
  const grid_coord& sy = sizeCoord.get2 ();

  const grid_coord& pz = position.get3 ();
  const grid_coord& sz = sizeCoord.get3 ();

  return px * sy * sz + py * sz + pz;
} /* Grid<GridCoordinate3D>::calculateIndexFromPosition */

#endif /* MODE_DIM3 */

/**
 * Calculate position coordinate from one-dimensional index
 */
template <>
GridCoordinate1D
Grid<GridCoordinate1D>::calculatePositionFromIndex (grid_coord index) const /**< index in grid */
{
  return GRID_COORDINATE_1D (index, getSize ().getType1 ());
} /* Grid<GridCoordinate1D>::calculatePositionFromIndex */

#if defined (MODE_DIM2) || defined (MODE_DIM3)

/**
 * Calculate position coordinate from one-dimensional index
 */
template <>
GridCoordinate2D
Grid<GridCoordinate2D>::calculatePositionFromIndex (grid_coord index) const /**< index in grid */
{
  const grid_coord& sx = size.get1 ();
  const grid_coord& sy = size.get2 ();

  grid_coord x = index / sy;
  index %= sy;
  grid_coord y = index;

  return GRID_COORDINATE_2D (x, y, getSize ().getType1 (), getSize ().getType2 ());
} /* Grid<GridCoordinate2D>::calculatePositionFromIndex */

#endif /* MODE_DIM2 || MODE_DIM3 */

#if defined (MODE_DIM3)

/**
 * Calculate position coordinate from one-dimensional index
 */
template <>
GridCoordinate3D
Grid<GridCoordinate3D>::calculatePositionFromIndex (grid_coord index) const /**< index in grid */
{
  const grid_coord& sy = size.get2 ();
  const grid_coord& sz = size.get3 ();

  grid_coord tmp = sy * sz;
  grid_coord x = index / tmp;
  index %= tmp;
  grid_coord y = index / sz;
  index %= sz;
  grid_coord z = index;

  return GRID_COORDINATE_3D (x, y, z, getSize ().getType1 (), getSize ().getType2 (), getSize ().getType3 ());
} /* Grid<GridCoordinate3D>::calculatePositionFromIndex */

#endif /* MODE_DIM3 */
