struct Point {
  int x, y;
};

int orientation(Point a, Point b, Point c) {
  int val = (b.y - a.y) * (c.x - b.x) -
            (b.x - a.x) * (c.y - b.y);
  if (val == 0)
    return 0;                // collinear
  return (val > 0) ? 1 : 2;  // 1 = clockwise, 2 = counter-clockwise
}

bool onSegment(Point a, Point b, Point c) {
  return b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
         b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y);
}

bool intersect(Point p1, Point q1, Point p2, Point q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
    return true;

  // Special cases (collinear)
  if (o1 == 0 && onSegment(p1, p2, q1))
    return true;
  if (o2 == 0 && onSegment(p1, q2, q1))
    return true;
  if (o3 == 0 && onSegment(p2, p1, q2))
    return true;
  if (o4 == 0 && onSegment(p2, q1, q2))
    return true;

  return false;
}
