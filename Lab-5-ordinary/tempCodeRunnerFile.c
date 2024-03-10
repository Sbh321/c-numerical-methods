
  printf("Enter initial values of x & y\n");
  scanf("%f%f",&x0,&y0);
  printf("Enter x at which function to be evaluated\n");
  scanf("%f",&x);
  y=y0;
  y=y0+y1(x);
  y=y0+y2(x);
  y=y0+y3(x);
  printf("Function value at x=%f is %f\n",x,y);
  getch();
  return 0;
}