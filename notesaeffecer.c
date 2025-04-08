void init_camera_pix_ray(t_pix *pix, t_camera *cam) {
    t_coord *p_viewport;
    t_coord *v_direction;
    t_coord *vn_direction;
    float    *m_inverse;
    t_coord *p_origin;
    t_coord *pixl;

    // OK Point cible dans le repère caméra
    p_viewport = create_point(pix->vpx, pix->vpy, -1.0);

    // OK Obtenir la matrice inverse pour le changement de repère
    m_inverse = inverted_matrix_44(cam->m_transf);
    if (!m_inverse) {
        printf("aieaieaie\n");
        return;
    }


    // Origine de la caméra dans le repère monde
    p_origin = matrix_multiplication_44_coord(m_inverse, create_point(0, 0, 0));

    // Point final transformé dans le repère monde
    pixl = matrix_multiplication_44_coord(m_inverse, p_viewport);

    // Direction du rayon dans le repère monde
    v_direction = substraction(pixl, p_origin);
    vn_direction = normalize_vector(v_direction);

    // Afficher l'étape pour déboguer
    printf("Camera origin: (%f, %f, %f)\n", p_origin->x, p_origin->y, p_origin->z);
    printf("Ray direction: (%f, %f, %f)\n", vn_direction->x, vn_direction->y, vn_direction->z);

    // Créer le rayon
    pix->r_original = create_ray(p_origin, vn_direction);

    // Libérer les objets temporaires
    free(p_viewport);
    free(v_direction);
    free(vn_direction); // S'il est alloué
    free(pixl);
    free(m_inverse); // S'il a été alloué dynamiquement
}