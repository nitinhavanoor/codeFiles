function A = generate_feature_matrix(B1,B2,B3,B4,B5,B6,B7,B8,B9,ext);

A = zeros(9,(450*600));

for i = 1 : (450*600)
    A(1,i) = B1(i);
    A(2,i) = B2(i);
    A(3,i) = B3(i);
    A(4,i) = B4(i);
    A(5,i) = B5(i);
    A(6,i) = B6(i);
    A(7,i) = B7(i);
    A(8,i) = B8(i);
    A(9,i) = B9(i);
end
end