clc;
clear all;
close all;

%read texture images and extend to 602 X 452

image = readraw('comb.raw',450,600);
    imagedata1 = image_extend(image);



    L_3 = (1/6) * [1 2 1];
    
    E_3 = (1/2) * [-1 0 1];
    
    S_3 = (1/2) * [1 -2 1];
    
%generate filters

filter1 = generate_filter(L_3,L_3);
filter2 = generate_filter(L_3,E_3);
filter3 = generate_filter(L_3,S_3);
filter4 = generate_filter(E_3,L_3);
filter5 = generate_filter(E_3,E_3);
filter6 = generate_filter(E_3,S_3);
filter7 = generate_filter(S_3,L_3);
filter8 = generate_filter(S_3,E_3);
filter9 = generate_filter(S_3,S_3);
    
 
% %perform filtering of each image
    
filtered_image1 = filter_image(filter1,imagedata1);
filtered_image2 = filter_image(filter2,imagedata1);
filtered_image3 = filter_image(filter3,imagedata1);
filtered_image4 = filter_image(filter4,imagedata1);
filtered_image5 = filter_image(filter5,imagedata1);
filtered_image6 = filter_image(filter6,imagedata1);
filtered_image7 = filter_image(filter7,imagedata1);
filtered_image8 = filter_image(filter8,imagedata1);
filtered_image9 = filter_image(filter9,imagedata1);


% extend rows and column 472 X 622
filtered_image1_ext11 = image_extend_11(filtered_image1);
filtered_image2_ext11 = image_extend_11(filtered_image2);
filtered_image3_ext11 = image_extend_11(filtered_image3);
filtered_image4_ext11 = image_extend_11(filtered_image4);
filtered_image5_ext11 = image_extend_11(filtered_image5);
filtered_image6_ext11 = image_extend_11(filtered_image6);
filtered_image7_ext11 = image_extend_11(filtered_image7);
filtered_image8_ext11 = image_extend_11(filtered_image8);
filtered_image9_ext11 = image_extend_11(filtered_image9);


%energy computation

energy1 = compute_energy(filtered_image1_ext11,11);
energy2 = compute_energy(filtered_image2_ext11,11);
energy3 = compute_energy(filtered_image3_ext11,11);
energy4 = compute_energy(filtered_image4_ext11,11);
energy5 = compute_energy(filtered_image5_ext11,11);
energy6 = compute_energy(filtered_image6_ext11,11);
energy7 = compute_energy(filtered_image7_ext11,11);
energy8 = compute_energy(filtered_image8_ext11,11);
energy9 = compute_energy(filtered_image9_ext11,11);

energy1 = energy1 ./ energy1;
energy2 = energy2 ./ energy1;
energy3 = energy3 ./ energy1;
energy4 = energy4 ./ energy1;
energy5 = energy5 ./ energy1;
energy6 = energy6 ./ energy1;
energy7 = energy7 ./ energy1;
energy8 = energy8 ./ energy1;
energy9 = energy9 ./ energy1;

%generate feature matrix

data_11 = generate_feature_matrix(energy1,energy2,energy3,energy4,energy5,energy6,energy7,energy8,energy9);

labels_11 = kmeans(data_11',6);

%generate image and display


generate_and_display(labels_11);

% extend rows and column 480 X 630
filtered_image1_ext15 = image_extend_15(filtered_image1);
filtered_image2_ext15 = image_extend_15(filtered_image2);
filtered_image3_ext15 = image_extend_15(filtered_image3);
filtered_image4_ext15 = image_extend_15(filtered_image4);
filtered_image5_ext15 = image_extend_15(filtered_image5);
filtered_image6_ext15 = image_extend_15(filtered_image6);
filtered_image7_ext15 = image_extend_15(filtered_image7);
filtered_image8_ext15 = image_extend_15(filtered_image8);
filtered_image9_ext15 = image_extend_15(filtered_image9);


%energy computation

energy11 = compute_energy(filtered_image1_ext15,15);
energy21 = compute_energy(filtered_image2_ext15,15);
energy31 = compute_energy(filtered_image3_ext15,15);
energy41 = compute_energy(filtered_image4_ext15,15);
energy51 = compute_energy(filtered_image5_ext15,15);
energy61 = compute_energy(filtered_image6_ext15,15);
energy71 = compute_energy(filtered_image7_ext15,15);
energy81 = compute_energy(filtered_image8_ext15,15);
energy91 = compute_energy(filtered_image9_ext15,15);
% 
% energy11 = energy11 ./ energy11;
% energy21 = energy21 ./ energy11;
% energy31 = energy31 ./ energy11;
% energy41 = energy41 ./ energy11;
% energy51 = energy51 ./ energy11;
% energy61 = energy61 ./ energy11;
% energy71 = energy71 ./ energy11;
% energy81 = energy81 ./ energy11;
% energy91 = energy91 ./ energy11;

%generate feature matrix

data_15 = generate_feature_matrix(energy11,energy21,energy31,energy41,energy51,energy61,energy71,energy81,energy91);

labels_15 = kmeans(data_15',6,'Replicates',25);

%generate image and display


generate_and_display(labels_15);
        
            
            





% extend rows and column 510 X 660
filtered_image1_ext30 = image_extend_30(filtered_image1);
filtered_image2_ext30 = image_extend_30(filtered_image2);
filtered_image3_ext30 = image_extend_30(filtered_image3);
filtered_image4_ext30 = image_extend_30(filtered_image4);
filtered_image5_ext30 = image_extend_30(filtered_image5);
filtered_image6_ext30 = image_extend_30(filtered_image6);
filtered_image7_ext30 = image_extend_30(filtered_image7);
filtered_image8_ext30 = image_extend_30(filtered_image8);
filtered_image9_ext30 = image_extend_30(filtered_image9);


%energy computation

energy111 = compute_energy(filtered_image1_ext30,30);
energy211 = compute_energy(filtered_image2_ext30,30);
energy311 = compute_energy(filtered_image3_ext30,30);
energy411 = compute_energy(filtered_image4_ext30,30);
energy511 = compute_energy(filtered_image5_ext30,30);
energy611 = compute_energy(filtered_image6_ext30,30);
energy711 = compute_energy(filtered_image7_ext30,30);
energy811 = compute_energy(filtered_image8_ext30,30);
energy911 = compute_energy(filtered_image9_ext30,30);
% 
% energy11 = energy11 ./ energy11;
% energy21 = energy21 ./ energy11;
% energy31 = energy31 ./ energy11;
% energy41 = energy41 ./ energy11;
% energy51 = energy51 ./ energy11;
% energy61 = energy61 ./ energy11;
% energy71 = energy71 ./ energy11;
% energy81 = energy81 ./ energy11;
% energy91 = energy91 ./ energy11;

%generate feature matrix

data_30 = generate_feature_matrix(energy111,energy211,energy311,energy411,energy511,energy611,energy711,energy811,energy911);

labels_30 = kmeans(data_30',6,'Replicates',25);

%generate image and display


generate_and_display(labels_30);
        
            
            

