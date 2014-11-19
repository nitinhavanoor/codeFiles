function A = generate_filter(C,B);


A = zeros(3,3);

for i = 1 : 3
    for j = 1 : 3
        A(i,j) = C(i) * B(j);
    end
end
end
