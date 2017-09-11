algebraic3d
solid field1 = ellipsoid (0, 0, 0 ; 0, 0, 2; 0, 1, 0 ; 2.5, 0, 0);
solid field2 = cylinder ( 0.5 , 0.5 , 0 ; 0.5 , 0.5 , 1 ; 1) ;
solid field3 = orthobrick ( 0 , 0 , 0 ; 5 , 3 , 3 ) ;
solid field4 = field1 and not field2;
solid field5 = field1 and not field3;
solid field = field5 and field4;
tlo field3;
